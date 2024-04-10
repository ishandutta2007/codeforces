//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <string>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <limits.h>
#include <tuple>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e5+10,M=17;
ll dp[M][N];
int phi[N];
vector <int> p[N];
ll seg[N*4];
int lazy[N*4];
void shift(ll nod){
    seg[nod*2]+=lazy[nod];
    seg[nod*2+1]+=lazy[nod];
    lazy[nod*2]+=lazy[nod];
    lazy[nod*2+1]+=lazy[nod];
    lazy[nod]=0;
}
void upd(int nod,int l,int r,int L,int R,int val){
    if (l>=R || L>=r) return;
    if (l>=L && r<=R){
        seg[nod]+=val;
        lazy[nod]+=val;
        return ;
    }
    shift(nod);
    int mid=(r+l)/2;
    upd(nod*2,l,mid,L,R,val);
    upd(nod*2+1,mid,r,L,R,val);
    seg[nod]=min(seg[nod*2],seg[nod*2+1]);
}
ll get(int nod,int l,int r,int L,int R){
    if (l>=R || L>=r) return (ll)1e15;
    if (l>=L && r<=R) return seg[nod];
    shift(nod);
    int mid=(r+l)/2;
    return min(get(nod*2,l,mid,L,R),get(nod*2+1,mid,r,L,R));
}
void build(int nod,int l,int r,int id){
    lazy[nod]=0;
    if (r-l==1){
        seg[nod]=dp[id][l];
        return ;
    }
    int mid=(r+l)/2;
    build(nod*2,l,mid,id);
    build(nod*2+1,mid,r,id);
    seg[nod]=min(seg[nod*2],seg[nod*2+1]);
}
int32_t main(){
    sync;
    
    
    for(int i = 1; i < N; i++){
        phi[i] += i;
        for(int j=2*i;j<N;j+=i) phi[j]-=phi[i];
        for(int j=i;j<N;j+=i) p[j].pb(i);
    }
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            dp[i][j]=(ll)1e15;
        }
    }
    dp[1][1]=1;
    for (int i=2;i<N;i++){
        dp[1][i]=1ll*i*(i-1)/2+i;
    }
    for (int j=2;j<M;j++){
      //  cout << " lerfjien " << get(1,0,N+1,1,2) << endl;
        build(1,0,N+1,j-1);
        for (int i=1;i<N;i++){
            
            for (auto u : p[i]){
                if (u<10 && i>N/2) continue;
                //if (j<=2 && i<=6) cout << z << endl;
                upd(1,0,N+1,0,u,phi[i/u]);
            }
            dp[j][i]=seg[1];
        }
    }
    
    int q;
    cin >> q;
    while(q--){
        int n,k;
        cin >> n >> k;
        if (k>=M){
            cout << n << "\n";
        }
        else{
            cout << dp[k][n] << "\n";
        }
    }
     
}