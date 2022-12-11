#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, idx, maxi;
    Node * lft, * rht;
    Node * cop(){
        Node *n = new Node();
        n->l = l, n->r = r;
        n->idx = idx, n->maxi = maxi;
        n->lft = lft, n->rht = rht;
        return n;
    }
};

int N, M = 500000, Q;
int lst[500005], cur[500005];
Node * rt[500005];

inline Node * build(int l, int r){
    Node *n = new Node();
    n->l = l, n->r = r;
    if(l == r){
        return n;
    }
    int mid = l+r>>1;
    n->lft = build(l, mid);
    n->rht = build(mid+1, r);
    return n;
}

inline Node * upd(int p, int v, int a, Node * x){
    Node * n = x->cop();
    if(n->l == n->r){
        n->idx = a;
        n->maxi = v;
        return n;
    }
    int mid = n->l + n->r >> 1;
    if(p <= mid){
        n->lft = upd(p, v, a, n->lft);
    }
    else{
        n->rht = upd(p, v, a, n->rht);
    }
    if(n->lft->maxi > n->rht->maxi){
        n->idx = n->lft->idx;
        n->maxi = n->lft->maxi;
    }
    else{
        n->idx = n->rht->idx;
        n->maxi = n->rht->maxi;
    }
    return n;
}

inline pair<int, int> query(int l, int r, Node * n){
    if(n->l == l && n->r == r){
        return {n->idx, n->maxi};
    }
    int mid = n->l + n->r >> 1;
    if(r <= mid){
        return query(l, r, n->lft);
    }
    else if(l > mid){
        return query(l, r, n->rht);
    }
    else{
        pair<int, int> p = query(l, mid, n->lft), q = query(mid+1, r, n->rht);
        if(p.second > q.second){
            return p;
        }
        else{
            return q;
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    rt[0] = build(-M, N);
    for(int i = 1; i<=M; i++){
        cur[i] = -i;
    }
    for(int i =1 ; i<=N; i++){
        rt[i] = rt[i-1]->cop();
        int n;
        cin >> n;
        rt[i] = upd(lst[n], 0, 0, rt[i]);
        lst[n] = cur[n];
        cur[n] = i;
        rt[i] = upd(lst[n], cur[n], n, rt[i]);
    }
    cin >> Q;
    while(Q--){
        int l, r;
        cin >> l >> r;
        pair<int, int> p = query(-M, l-1, rt[r]);
        if(p.second >= l){
            cout << p.first << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
}