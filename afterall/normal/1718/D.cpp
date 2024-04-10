#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=3e5+100;
ll a[N];
ll p[N];
vector <int> g[N];
ll par[N];
ll parOk[N];
ll rapOk[N];
ll mx[N],mn[N];
ll cnt=0;
ll T;
ll dfs(ll v,ll R){
    ll L=0;
    if (a[v]!=0){
        R=a[v];
        L=a[v];
    }
    mx[v]=R;
    for (auto u : g[v]){
        L=max(L,dfs(u,R));
    }
    mn[v]=L;
    if (a[v]!=0){
        mx[v]=-1;
        mn[v]=-1;
    }
    return L;

}
ll solve(vector <pii> a,vector <int> b){
    multiset <int> s;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    if (a.size()!=b.size()) return 0;
    for (int i=0;i<b.size();i++){
        while(a.size() && a.back().F<=b[i]){
         //   cout << b[i] << " " << a.back().S << endl;
            s.insert(a.back().S);
            a.pop_back();
        }

        if (s.size()==0) return 0;
        if (*s.begin()<b[i]) return 0;
        s.erase(s.begin());
    }
    return 1;
}
void Main(){
    ll n,q;
    cin >> n >> q;

    for (int i=1;i<=n;i++){
        g[i].clear();
        mx[i]=0;
        mn[i]=0;
        parOk[i]=0;
        rapOk[i]=0;
        cin >> p[i];
    }
    ll k=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        k+=(a[i]==0);
    }
    vector <int> b;
    for (int i=0;i<k-1;i++){
        ll x;
        cin >> x;
        b.pb(x);
    }
    vector <int> agh;
    p[0]=1e9;
    p[n+1]=1e9;
    agh.pb(0);
    for (int i=1;i<=n;i++){
        while(p[agh.back()]<p[i]) agh.pop_back();
        par[i]=agh.back();
        agh.pb(i);
    }
    agh.clear();
    agh.pb(n+1);
    ll p1=0;
    ll root=0;
    for (int i=n;i;i--){
        while(p[agh.back()]<p[i]) agh.pop_back();
        if (p[par[i]]>p[agh.back()]) par[i]=agh.back();
        agh.pb(i);
        if (par[i]==0 || par[i]==n+1) root=i;
        else{
            g[par[i]].pb(i);
            //cout << i << " par " << par[i] << endl;
            if (a[i]!=0 && a[par[i]]!=0 && a[i]>a[par[i]]) p1=1;
        }
    }
    dfs(root,1e9);
    vector <pii> s;
    for (int i=1;i<=n;i++){
        if (mx[i]!=-1){
            s.pb({mn[i],mx[i]});
           // if (mn[i]>mx[i]) p1=1;
        }
    }
    sort(s.begin(),s.end());
    sort(b.begin(),b.end());
    vector <pii> S=s;
    reverse(S.begin(),S.end());
    vector <int> D=b;
    multiset <pii> SS;
    vector <pii> W;
    int counter=0;
    int isok=1;
    for (int i=0;i<D.size();i++){
        while(S.size() && S.back().F<=D[i]){
            SS.insert({S.back().S,S.size()});
            S.pop_back();
        }
        if (SS.size()==0) {
            isok=0;
            continue;
        }
        if (SS.size()){
            W.pb(s[s.size()-SS.begin()->S]);
        }
        if (SS.begin()->F>D[i]){
            counter+=isok;
            SS.erase(SS.begin());
        }
        else{
            isok=0;
            SS.erase(SS.begin());
            i--;
        }
    }
    for (int i=1;i<=counter;i++){
        parOk[i]=1;
    }
    while(SS.size()){
        W.pb(s[s.size()-SS.begin()->S]);
        SS.erase(SS.begin());
    }
    s=W;
    
    ll l=-1,r=k-1;

    l=0;
    r=k;
    while(r-l>1){
        ll mid=(r+l)/2;
        vector <pii> x;
        for (int i=mid;i<k;i++){
            x.pb(s[i]);
        }
        vector <int> y;
        for (int i=mid-1;i<k-1;i++) y.pb(b[i]);
      //  cout << l << " " << r << " " << mid << endl;
        if (solve(x,y)) r=mid;
        else l=mid;
    }
    for (int i=l+1;i<k;i++) rapOk[i+1]=1;
    parOk[0]=1;
    rapOk[k+1]=1;
    ll minw=1e9,maxw=0;
    vector <pii> good;
    for (int i=1;i<=k;i++){
        if (parOk[i-1] && rapOk[i+1]){
            minw=min(minw,s[i-1].F);
            maxw=max(maxw,s[i-1].S);

        }
    }
    /*
    for (int i=0;i<s.size();i++){
        cout << s[i].F << " mamad " << s[i].S << endl;
    }
    for (int i=1;i<=k;i++){
        cout << parOk[i] << " " << rapOk[i] << endl;
    }
    */
    while(q--){
        ll x;
        cin >> x;
        cnt++;
        
    
        if (p1){
            cout << "NO" << endl;
            continue;
        }
        if (x>=minw && x<=maxw){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
        
        
    }
}
int32_t main(){
    sync;
    cin >> T;
    for (int i=0;i<T;i++) Main();
}
/*
1
45 1
24 4 35 17 29 33 28 37 3 36 43 6 22 13 10 21 15 34 30 38 18 45 9 39 23 7 11 44 31 1 14 8 40 25 2 19 27 16 26 12 32 20 42 5 41 
135983 117570 313841 145850 0 273676 239916 868590 111503 0 929394 406821 427851 118659 94633 232984 196042 612628 529017 741608 261718 976070 305032 400411 345427 334162 337992 921983 648494 76105 
0 391132 899923 702092 6959 686578 765950 533819 668046 460675 855822 42746 911549 0 497291 
175399 494755 851884 
660968
*/