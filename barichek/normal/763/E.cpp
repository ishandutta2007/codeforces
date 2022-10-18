#pragma GCC optimize("Ofast")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4")
 
#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif
 
#define F first
#define S second
#define MP make_pair
#define PB push_back
 
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
 
#if __APPLE__
#define D for (bool _FLAG = true; _FLAG; _FLAG = false)
#define LOG(...) print(#__VA_ARGS__" ::", __VA_ARGS__) << endl
template <class ...Ts> auto &print(Ts ...ts) { return ((cerr << ts << " "), ...); }
#else
#define D while (false)
#define LOG(...)
#endif
 
const int max_n = 1e5+10, inf = 1000111222;
 
const int max_k = 5+2;
 
bool reb[max_n][max_k];
 
int L[max_n];
int R[max_n];
 
int ans[max_n];
 
int id_border_as_left[max_n][max_k];
int ans_as_left[max_n];
int id_border_as_right[max_n][max_k];
int ans_as_right[max_n];
 
int p[max_n];
void recreate_p(int i)
{
    p[i]=i;
}
int f(int v)
{
    return p[v]==v ? v : p[v]=f(p[v]);
}
void unite(int u,int v,int& ans)
{
    u=f(u);
    v=f(v);
    if (u!=v){
        p[u]=v;
        ans--;
    }
}
 
void solve(int l,int r,const vector<int> &req)
{
    if (req.empty()){
        return;
    }
//    cerr<<l<<" "<<r<<"\n";
    if (l==r){
        for (auto i:req){
            ans[i]=1;
        }
        return;
    }
    int m=(l+r)/2;
    vector<int> req_l;
    vector<int> req_r;
    vector<int> cur;
    for (auto i:req){
        if (R[i]<=m){
            req_l.pb(i);
        }
        else if (L[i]>=m+1){
            req_r.pb(i);
        }
        else{
            cur.pb(i);
        }
    }
    solve(l,m,req_l);
    solve(m+1,r,req_r);
 
    for (int i=m;i>=l;i--){
        recreate_p(i);
 
        ans_as_left[i]=(i==m ? 0 : ans_as_left[i+1]) + 1;
 
        for (int j=0;j<max_k;j++){
            if (i+j<=m && reb[i][j]){
                unite(i,i+j,ans_as_left[i]);
            }
        }
 
        for (int j=0;j<max_k;j++){
            if (m-j>=l){
                id_border_as_left[i][j]=f(m-j);
            }
        }
    }
    for (int i=m+1;i<=r;i++){
        recreate_p(i);
 
        ans_as_right[i]=(i==m+1 ? 0 : ans_as_right[i-1]) + 1;
 
        for (int j=0;j<max_k;j++){
            if (i-j>=m+1 && reb[i-j][j]){
                unite(i-j,i,ans_as_right[i]);
            }
        }
 
        for (int j=0;j<max_k;j++){
            if (m+1+j<=r){
                id_border_as_right[i][j]=f(m+1+j);
            }
        }
    }
    for (auto i:cur){
//        cerr<<"ans["<<i<<"] :: "<<ans_as_left[L[i]]<<"+"<<ans_as_right[R[i]]<<"\n";
        ans[i]=ans_as_left[L[i]]+ans_as_right[R[i]];
        for (int j=0;j<max_k;j++){
            if (m-j>=l){
                recreate_p(id_border_as_left[L[i]][j]);
            }
            if (m+1+j<=r){
                recreate_p(id_border_as_right[R[i]][j]);
            }
        }
 
        for (int j1=0;j1<max_k;j1++){
            if (m-j1>=L[i]){
                for (int j2=0;j2<max_k;j2++){
                    if (m+1+j2<=R[i]){
                        if (j1+1+j2<max_k && reb[m-j1][j1+1+j2]){
                            unite(id_border_as_left[L[i]][j1],id_border_as_right[R[i]][j2],ans[i]);
//                            cerr<<"unite of "<<m-j1<<" "<<m+1+j2<<" :: "<<ans[i]<<"\n";
                        }
                    }
                }
            }
        }
    }
}
#include<ctime>
void sleep(double seconds)
{
    double start = clock();
    while ((clock() - start) / CLOCKS_PER_SEC < seconds){
        /// wait
    }
}
 
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    sleep(6.5);
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n,k;
    cin>>n>>k;
    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if (u>v){
            swap(u,v);
        }
        u--;
        v--;
 
        reb[u][v-u]=1;
    }
    int q;
    cin>>q;
    vector<int> req;
    for (int i=0;i<q;i++){
        cin>>L[i]>>R[i];
        L[i]--;
        R[i]--;
        req.pb(i);
    }
    solve(0,n-1,req);
    for (int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
    }
}