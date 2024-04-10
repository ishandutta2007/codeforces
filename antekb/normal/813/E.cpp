#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    node* l=nullptr, *r=nullptr;
    ll val=0;
    node(ll _val=0){val=_val;}
};

node* left(node* v){
    if(!v)return nullptr;
    return v->l;
}
node* right(node*v){
    if(!v)return nullptr;
    return v->r;
}
ll Val(node*v){
    if(!v)return 0;
    return v->val;
}
void upd(node*v){
    if(!v)return;
    v->val=Val(left(v))+Val(right(v));
}
node* add(node* v, int k, int lev, int c){
    node* u=new node(Val(v)+c);
    if(lev==0)return u;
    u->l=left(v);
    u->r=right(v);
    if(k&(1<<(lev-1))){
        u->r=add(right(v), k^(1<<(lev-1)), lev-1, c);
    }
    else u->l=add(left(v), k, lev-1, c);
    upd(u);
    return u;
}
ll sum(node* v, int l, int r, int L, int R){
    //cout<<L<<" "<<R<<" "<<Val(v)<<"\n";
    if(L==l && R==r){
        return Val(v);
    }
    int M=(L+R)/2;
    ll res=0;
    if(l<=M)res+=sum(left(v), l, min(r, M), L, M);
    if(r>=M+1)res+=sum(right(v), max(l, M+1), r, M+1, R);
    return res;
}
node* create(int lev){
    node*v=new node(0);
    if(lev){
        v->l=create(lev-1);
        v->r=create(lev-1);
    }
    return v;
}
const int N=1e5+5;
vector<node*> nodes;
vector<int> tab[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int K=18;
    int n, k;
    cin>>n>>k;
    vector<int> V(n);
    for(int &i:V)cin>>i;
    nodes.resize(n+1);
    nodes[0]=create(K);
    node*root=nodes[0];
    for(int i=n-1; i>=0;i--){
        tab[V[i]].push_back(i);
        if(tab[V[i]].size()>k){
            //cout<<tab[V[i]][tab[V[i]].size()-k-1];
            root=add(root, tab[V[i]][tab[V[i]].size()-k-1], K, 1);
        }
        nodes[i]=root;
    }
    int q;
    cin>>q;
    int lst=0;
    while(q--){
        int l, r;cin>>l>>r;
        l=(lst+l)%n;
        r=(lst+r)%n;
        if(l>r)swap(l, r);
        //cout<<l<<" "<<r<<"\n";
        lst=r-l+1-sum(nodes[l], l, r, 0, (1<<K)-1);
        cout<<lst<<"\n";
    }
}