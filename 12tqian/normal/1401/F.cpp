#include<bits/stdc++.h>
using namespace std;
const int MAX = 19;
struct node{
    node* l;
    node* r;
    bool reversed[MAX], swapped[MAX];
    int le, ri;
    int depth;
    long long sum = 0;
    long long lazy = 0;
    node(int _le, int _ri, int _depth){
        le = _le, ri = _ri, depth = _depth;
        for(int i = 0; i < MAX; i++){
            reversed[i] = swapped[i] = false;
        }
        if(le != ri){
            int mid = (le + ri) / 2;
            l = new node(le, mid, depth - 1);
            r = new node(mid + 1, ri, depth - 1);
        }
        else{
            l = r = nullptr;
        }
    }
    void pull(){
        le += lazy, ri += lazy;
        if(le != ri){
            l->lazy += lazy;
            r->lazy += lazy;
        }
        lazy = 0;
        if(le != ri) sum = l->sum + r->sum;
    }
    void push(){
        le += lazy, ri += lazy;
        if(le != ri){
            l->lazy += lazy;
            r->lazy += lazy;
        }
        lazy = 0;
        if(le == ri) return;
        if(reversed[depth]){
            l->lazy += (1 << (depth - 1));
            r->lazy -= (1 << (depth - 1));
            swap(l, r);
            l->reversed[depth - 1] ^= 1;
            r->reversed[depth - 1] ^= 1;
            reversed[depth] = false;
        }
        if(swapped[depth]){
            l->lazy += (1 << (depth - 1));
            r->lazy -= (1 << (depth - 1));
            swap(l, r);
            swapped[depth] = false;
        }
        for(int i = 0; i < depth; i++){
            if(swapped[i]){
                l->swapped[i] ^= 1;
                r->swapped[i] ^= 1;
                swapped[i] = false;
            }
            if(reversed[i]){
                l->reversed[i] ^= 1;
                r->reversed[i] ^= 1;
                reversed[i] = false;
            }
        }
    }
    void point_update(int p, long long k){
        push(); pull();
        if(le == ri){
            sum = k;
            return;
        }
        int mid = (le + ri) / 2;
        if(p <= mid) l->point_update(p, k);
        else r->point_update(p, k);
        pull();
    }
    void reverse_update(int k){
        reversed[k] ^= 1;
    }
    void swap_update(int k){
        swapped[k + 1] ^= 1;
    }
    long long query(int lo, int hi){
        push(); pull();
        if(le == lo && ri == hi) return sum;
        long long ret = 0;
        int mid = (le + ri) / 2;
        if(lo <= mid){
            ret += l->query(lo, min(hi, mid));
        }
        if(hi >= mid + 1){
            ret += r->query(max(lo, mid + 1), hi);
        }
        return ret;
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    node seg(0, (1 << n) - 1, n);
    for(int i = 0; i < (1 << n); i++){
        int x; cin >> x;
        seg.point_update(i, x);
    }
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x, k; cin >> x >> k; x--;
            seg.point_update(x, k);
        }
        else if(t == 2){
            int k; cin >> k;
            seg.reverse_update(k);
        }
        else if(t == 3){
            int k; cin >> k;
            seg.swap_update(k);
        }
        else{
            int l, r; cin >> l >> r; l--; r--;
            cout << seg.query(l, r) << '\n';
        }
    }
    return 0;
}