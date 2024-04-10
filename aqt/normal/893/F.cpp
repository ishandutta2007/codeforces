#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, mini;
    Node *lft, *rht;
    Node* cop(){
        Node *n = new Node();
        n->l = l;
        n->r = r;
        n->mini = mini;
        n->lft = lft;
        n->rht = rht;
        return n;
    }
};

int N, R, Q;
Node *rt[100005];
int ET[200005], lft[100005], rht[100005], T = 0;
int arr[100005], dep[100005];
vector<int> graph[100005];
vector<int> group[100005];

void dfs(int n, int p){
    dep[n]++;
    ET[++T] = n;
    lft[n] = T;
    for(int e : graph[n]){
        if(e != p){
            dep[e] = dep[n];
            dfs(e, n);
        }
    }
    ET[++T] = n;
    rht[n] = T;
}


Node *build(int l, int r){
    Node *n = new Node();
    n->l = l;
    n->r = r;
    if(l == r){
        n->mini = INT_MAX;
        return n;
    }
    int mid = l+r>>1;
    n->lft = build(l, mid);
    n->rht = build(mid+1, r);
    n->mini = min(n->lft->mini, n->rht->mini);
    return n;
}

Node *upd(int p, int v, Node *x){
    Node *n = x->cop();
    if(n->l == n->r){
        n->mini = v;
        return n;
    }
    int mid = n->l+n->r>>1;
    if(p <= mid){
        n->lft = upd(p, v, n->lft);
    }
    else{
        n->rht = upd(p, v, n->rht);
    }
    n->mini = min(n->lft->mini, n->rht->mini);
    return n;
}

int query(int l, int r, Node *n){
    if(n->l == l && n->r == r){
        return n->mini;
    }
    int mid = n->l + n->r >> 1;
    if(r <= mid){
        return query(l, r, n->lft);
    }
    else if(l > mid){
        return query(l, r, n->rht);
    }
    else{
        return min(query(l, mid, n->lft), query(mid+1, r, n->rht));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> R;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i= 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(R, 0);
    rt[0] = build(1, 2*N);
    for(int i = 1; i<=N; i++){
        group[dep[i]].push_back(i);
    }
    for(int i = 1; i<=N; i++){
        rt[i] = rt[i-1]->cop();
        for(int n : group[i]){
            rt[i] = upd(lft[n], arr[n], rt[i]);
        }
    }
    int ans = 0;
    cin >> Q;
    while(Q--){
        int n, d;
        cin >> n >> d;
        n = (n+ans)%N+1, d = (d+ans)%N;
        d += dep[n];
        d = min(d, N);
        cout << (ans = query(lft[n], rht[n], rt[d])) << "\n";
    }
}