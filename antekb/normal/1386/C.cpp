
#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef pair<int, int> pii;
const int N=2e5+5;
int R[N], czy[N], dp[N], siz[N];
pii E[N], E2[N];
int M;
pii Find(int x){
    if(x==R[x])return {x, 0};
    pii a=Find(R[x]);
    a.nd^=czy[x];
    return a;
}
void Union(int a, int b){
    //cout<<a<<"+"<<b<<"\n";
    if(a==b)return;
    if(siz[a]>siz[b])swap(a, b);
    siz[b]+=siz[a];
    R[a]=b;
    czy[a]^=1^czy[b];
    czy[b]=0;
}
void sep(int a, int b){
    //cout<<a<<"-"<<b<<"\n";
    if(a==b)return;
    czy[a]=0;
    czy[b]=0;
    if(siz[a]>siz[b])swap(a, b);
    siz[b]-=siz[a];
    R[a]=a;
}
void solve(int l, int r, int a, int b){
    //cout<<l<<" "<<r<<" "<<a<<" "<<b<<"\n";
    if(l>r)return;
    int m=(l+r)>>1;
    dp[m]=N;
    for(int i=l; i<m; i++){
        pii A=Find(E[i].st), B=Find(E[i].nd);
        E2[i]={A.st, B.st};
        if(A.st==B.st && (A.nd^B.nd^1)){
            dp[m]=i;
            break;
        }
        if(A.st!=B.st){
            czy[A.st]=A.nd;
            czy[B.st]=B.nd;
        }
        Union(A.st, B.st);
    }
    if(dp[m]<m){
        //cout<<"a";
        for(int i=dp[m]-1; i>=l; i--)sep(E2[i].st, E2[i].nd);
        solve(l, dp[m], a, b);
        for(int i=dp[m]+1; i<=r; i++)dp[i]=b;
        return;
    }
    for(int i=b; i>=a; i--){
        if(i<m){
            //cout<<"a";
            dp[m]=m-1;
            break;
        }
        pii A=Find(E[i].st), B=Find(E[i].nd);
        E2[i]={A.st, B.st};
        if(A.st==B.st && (A.nd^B.nd^1)){
            dp[m]=i;
            break;
        }
        //cout<<A.nd<<"_"<<B.nd<<"\n";
        if(A.st!=B.st){
            czy[A.st]=A.nd;
            czy[B.st]=B.nd;
        }
        Union(A.st, B.st);
    }
    //cout<<m<<" "<<dp[m]<<"\n";
    for(int i=dp[m]+1; i<=b; i++)sep(E2[i].st, E2[i].nd);
    pii A=Find(E[m].st), B=Find(E[m].nd);
    if(A.st==B.st && (A.nd^B.nd^1)){
        for(int i=m+1; i<=r; i++)dp[i]=b;
    }
    else{
        if(A.st!=B.st){
            czy[A.st]=A.nd;
            czy[B.st]=B.nd;
        }
        Union(A.st, B.st);
        solve(m+1, r, dp[m], b);
        sep(A.st, B.st);
    }
    for(int i=m-1; i>=l; i--){
        sep(E2[i].st, E2[i].nd);
    }
    for(int i=b; i>dp[m]; i--){
        A=Find(E[i].st), B=Find(E[i].nd);
        E2[i]={A.st, B.st};
        if(A.st!=B.st){
            czy[A.st]=A.nd;
            czy[B.st]=B.nd;
        }
        Union(A.st, B.st);
    }
    solve(l, m-1, a, dp[m]);
    for(int i=dp[m]+1; i<=b; i++)sep(E2[i].st, E2[i].nd);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin>>n>>m>>q;
    M=m;
    for(int i=1; i<=n+2 ;i++){
        R[i]=i;
        siz[i]=1;
    }
    for(int i=1; i<=m; i++){
        cin>>E[i].st>>E[i].nd;
    }
    E[m+1]={n+1, n+2};
    solve(1, m, 0, m+1);
    //for(int i=1; i<=m; i++)cout<<dp[i]<<"\n";
    while(q--){
        int l, r;
        cin>>l>>r;
        if(r>=dp[l])cout<<"NO\n";
        else cout<<"YES\n";
    }
}