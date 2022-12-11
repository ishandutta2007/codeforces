#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, lzy, mini;
    Node * lft, * rht;
};

int N, K, Q, M = INT_MAX;
int tbl[100005][20];

void pd(Node *& x){
    x->lft->mini = x->rht->mini = x->lzy;
    x->lft->lzy = x->rht->lzy = x->lzy;
    x->lzy = 0;
}

int getmini(int l, int r){
//    cout << l << " " << r << endl;
    if(l > r){
        return min(getmini(0, r), getmini(l, N-1));
    }
    int k = 31-__builtin_clz(r-l+1);
    return min(tbl[l][k], tbl[r-(1<<k)+1][k]);
}

void upd(int l, int r, int v, Node *& x){
    if(x->l == l && x->r == r){
        x->lzy = x->mini = v;
        return;
    }
    int mid = x->l + x->r >> 1;
    if(x->lft == NULL){
        x->lft = new Node(), x->rht = new Node();
        x->lft->l = x->l, x->rht->l = mid+1;
        x->lft->r = mid, x->rht->r = x->r;
        if(x->lft->r - x->lft->l + 1 >= N){
            x->lft->mini = M;
        }
        else{
            x->lft->mini = getmini(x->lft->l%N, x->lft->r%N);
        }
        if(x->rht->r - x->rht->l + 1 >= N){
            x->rht->mini = M;
        }
        else{
            x->rht->mini = getmini(x->rht->l%N, x->rht->r%N);
        }
    }
    if(x->lzy){
        pd(x);
    }
    if(r <= mid){
        upd(l, r, v, x->lft);
    }
    else if(l > mid){
        upd(l, r, v, x->rht);
    }
    else{
        upd(l, mid, v, x->lft);
        upd(mid+1, r, v, x->rht);
    }
    x->mini = min(x->lft->mini, x->rht->mini);
}

int query(int l, int r, Node *& x){
//    cout << l << " " << r << " " << x->l << " " << x->r << endl;
    if(x->l == l && x->r == r){
        return x->mini;
    }
    int mid = x->l + x->r >> 1;
    if(x->lft == NULL){
        x->lft = new Node(), x->rht = new Node();
        x->lft->l = x->l, x->rht->l = mid+1;
        x->lft->r = mid, x->rht->r = x->r;
        if(x->lft->r - x->lft->l + 1 >= N){
            x->lft->mini = M;
        }
        else{
            x->lft->mini = getmini(x->lft->l%N, x->lft->r%N);
        }
        if(x->rht->r - x->rht->l + 1 >= N){
            x->rht->mini = M;
        }
        else{
            x->rht->mini = getmini(x->rht->l%N, x->rht->r%N);
        }
    }
    if(x->lzy){
        pd(x);
    }
    if(r <= mid){
        return query(l, r, x->lft);
    }
    else if(l > mid){
        return query(l, r, x->rht);
    }
    else{
        return min(query(l, mid, x->lft), query(mid+1, r, x->rht));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i = 0; i<N; i++){
        cin >> tbl[i][0];
        M = min(tbl[i][0], M);
    }
    for(int d = 1; d<20; d++){
        for(int i = 0; i<N-(1<<d)+1; i++){
            tbl[i][d] = min(tbl[i][d-1], tbl[i+(1<<(d-1))][d-1]);
        }
    }
    cin >> Q;
    Node * rt = new Node();
    rt->l = 0, rt->r = N*K-1;
    rt->mini = M;
    while(Q--){
        int c, l, r;
        cin >> c >> l >> r;
        l--, r--;
        if(c == 1){
            int x;
            cin >> x;
            upd(l, r, x, rt);
        }
        else{
            cout << query(l, r, rt) << "\n";
        }
    }
}
/*
50 10
54 34 41 84 36 45 24 83 90 31 19 77 16 4 85 87 83 4 61 60 60 2 66 92 83 27 44 50 53 85 18 50 82 12 39 19 15 52 64 2 26 73 97 1 53 38 60 46 51 51
12
2 379 498
2 262 303
2 342 368
1 187 426 46
2 90 451
2 88 107
1 187 430 22
2 163 471
2 213 349
1 211 271 98
2 202 344
2 101 398
*/