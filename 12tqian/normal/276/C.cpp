#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
const long long MAX = 200005; //max number of nodes
const long long INF = 1000000;// need this for MinSegTree
struct SumSegTree {
    long long arr[MAX];
    //holding the sums
    long long tree[8*MAX];
    long long lazy[8*MAX];
    long long size[8*MAX];

    void push (long long node){
        if(lazy[node] == 0){
            return;
        }
        tree[node] += lazy[node] *size[node];
        lazy[2*node + 1] += lazy[node];
        lazy[2*node + 2] += lazy[node];
        lazy[node] = 0;
        return;
    }
    //builds from lo to hi, with node as root
    void build(long long lo, long long hi, long long node){
        if(lo == hi){
            tree[node] = arr[lo];
            size[node] = 1;
            return;
        }
        long long mid = (lo + hi)/2;
        build(lo, mid, 2*node + 1);
        build(mid + 1, hi, 2*node + 2);
        tree[node] = tree[2*node + 1] + tree[2*node+ 2];
        size[node] = size[2*node + 1] + size[2*node + 2];
    }
    //updates from i to j on a segment that's from lo to hi, each with val
    void update(long long lo, long long hi, long long node, long long i, long long j, long long val){
        if(hi<i || j<lo){
            return;
        }
        if(i<= lo && hi<= j){
            lazy[node] += val;
            push(node);
            return;
        }
        long long mid = (lo + hi)/2;
        update(lo, mid, 2*node+1, i, j, val);
        update(mid+1, hi, 2*node+2, i, j, val);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
    //query from i to j, with a segment tree from lot to hi with root at node
    long long query(long long lo, long long hi, long long node, long long i, long long j){
        if(hi<i || j<lo){
            return 0;
        }
        push(node);
        if(i<= lo && hi<= j){
            return tree[node];
        }
        long long mid = (lo+hi)/2;
        return query(lo, mid, 2*node + 1, i, j)+ query(mid+1, hi, 2*node +2, i, j);
    }
};
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
vector<long long> a;
vector<long long> b;
int main(){
    fast_io();
    long long n, q;
    cin >> n >> q;
    SumSegTree sst;
    sst.build(0, n-1, 0);
    for(long long i = 0; i<n; i++){
        long long d;
        cin >> d;
        a.emplace_back(d);
    }
    for(long long i = 0; i<q; i++){
        long long l, r;
        cin >> l >> r;
        l--;
        r--;
        sst.update(0, n-1, 0, l, r, 1);
    }
    for(long long i = 0; i<n; i++){
        b.emplace_back(sst.query(0, n-1, 0, i, i));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long total = 0;
    for(long long i = 0; i<n; i++){
        total += (a[i] * b[i]);
    }
    cout << total;
    return 0;
}