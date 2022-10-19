#include <iostream>
#include <algorithm>
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
typedef int ll;
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
const int N=6e5+100,M=3e5+5;
ll seg[N*2];
void upd(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod]=val;
        return ;
    }
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,l,mid,id,val);
    else upd(nod*2+1,mid,r,id,val);
    seg[nod]=max(seg[nod*2],seg[nod*2+1]);
}
ll get(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return -1;
    if (l>=L && r<=R) return seg[nod];
    ll mid=(r+l)/2;
    return max(get(nod*2,l,mid,L,R),get(nod*2+1,mid,r,L,R));
}
ll par[M];
vector <int> a[N];
deque <char> t[M];
vector <int> g[N];
ll mn;
ll tedad=0;
ll mark[M];
ll Compare(int x,int y){
    for (int i=0;i<min(t[x].size(),t[y].size());i++){
        if (t[x][i]<t[y][i]) return 1;
        if (t[y][i]<t[x][i]) return 0;
    }
    if (t[y].size()<=t[x].size()) return 0;
    return 1;
}
void dfs(ll v){
    
    vector <int> b;
    for (auto u : g[v]){
        dfs(u);
        if (u<=-mn){
            if (t[u].size()<t[v].size()){
                for (auto z : t[u]) t[v].pb(z);
            }
            else {
                swap(t[v],t[u]);
                for (int i=t[u].size();i;i--) t[v].push_front(t[u][i-1]);
            }
            continue;
        }
        
        while(b.size() && Compare(u, b.back())) b.pop_back();
        b.pb(u);
    }
    
    for (auto u : b){
        if (t[u].size()<t[v].size()){
            for (auto z : t[u]) t[v].pb(z);
        }
        else {
            swap(t[v],t[u]);
            for (int i=t[u].size();i;i--) t[v].push_front(t[u][i-1]);
        }
    }
    if (!mark[v]) t[v].pb(')');
    if (v!=0) t[v].push_front('(');
    
    for (auto u : g[v]){
        t[u].clear();
        t[u].shrink_to_fit();
    }
     
    
}
int32_t main(){
    sync;
    string s;
    cin >> s;
    ll n=s.size();
    for (int i=1;i<=n;i++){
        ll z=1;
        if (s[i-1]==')') z=-1;
        par[i]=par[i-1]+z;
    }
    for (int i=1;i<=n;i++){
        par[i]+=M;
        upd(1,1,n+1,i,par[i]);
    }
    for (int i=1;i<=n;i++){
        a[par[i]].pb(i);
    }
    string ans="";
    for (int i=1;i<=n;i++){
        if (s[i-1]==')'){
            ans+=')';
            continue;
        }
        ll z=par[i-1]-1;
        ll k=upper_bound(a[z].begin(),a[z].end(),i)-a[z].begin();
        
        ll nxt=n;
        if (k!=a[z].size()) nxt=a[z][k]-1;
        ll o=get(1,1,n+1,i,nxt+1);
        ll j=i;
        while(par[j]!=o) j++;
        for (int k=0;k<o-par[i-1];k++) ans+='(';
        i=j;
    }
    for (int i=0;i<N;i++){
        a[i].clear();
        a[i].shrink_to_fit();
    }
    n=ans.size();
    mn=0;
    ll cnt=0;
    for (int i=1;i<=n;i++){
        ll z=1;
        if (ans[i-1]==')') z=-1;
        cnt+=z;
        mn=min(mn,cnt);
    }
    reverse(ans.begin(),ans.end());
    for (int i=0;i<-mn;i++) ans+='(';
    reverse(ans.begin(),ans.end());
    n=ans.size();
    cnt-=mn;
    
    //cout << ans << endl;
    vector <int> agh;
    agh.pb(0);
    for (int i=1;i<=n;i++){
        if (ans[i-1]=='('){
            par[i]=agh.back();
            g[agh.back()].pb(i);
            agh.pb(i);
        }
        else {
            agh.pop_back();
        }
    }
    for (int i=0;i<agh.size();i++) mark[agh[i]]=1;
    dfs(0);
    ans="";
    for (auto u : t[0]) ans+=u;
  //  cout << ans << endl;
    reverse(ans.begin(),ans.end());
    for (int i=0;i<-mn;i++) ans.pop_back();
    reverse(ans.begin(), ans.end());
    ll last=ans.size()+1;
    ll z=0;
    for (int i=ans.size();i;i--){
        if (ans[i-1]==')') z++;
        else z--;
        if (z<0) z=0;
        if (z==0) last=i;
    }
    string jav="";
    for (int i=1;i<last;i++) jav+=ans[i-1];
    z=0;
    for (int i=last;i<=ans.size();i++) {
        if (ans[i-1]=='(') z++;
        else z--;
    }
    for (int i=1;i<=z;i++) jav+='(';
    
    cout << jav << endl;
}