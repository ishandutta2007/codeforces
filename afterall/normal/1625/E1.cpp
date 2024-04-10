#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=6e5+100;

ll fen[N];
ll len[N];
void add(ll idx,ll val){
    for (;idx<N;idx+=idx & (-idx)) fen[idx]+=val;
}
ll get(ll idx){
    ll s=0;
    for (;idx;idx-=idx & (-idx)) s+=fen[idx];
    return s;
}

vector <int> g[N];
ll st[N],fn[N],ts=1;

void dfs(ll v,ll p){
    st[v]=ts;
    for (auto u : g[v]){
        if (u==p) continue;
        ts++;
        dfs(u,v);
    }
    fn[v]=ts;
}
ll val[N];
ll what(ll x){
    return x*(x-1)/2;
}
ll par[N];
ll bk[N];
ll is[N];
vector <int> fe[N];
void ad(ll id,ll idx,ll val){
    for (;idx<fe[id].size();idx+=idx & (-idx)){
        fe[id][idx]+=val;
    }
}
ll ge(ll id,ll idx){
    ll s=0;
    for (;idx;idx-=idx & (-idx)) s+=fe[id][idx];
    return s;
}
int32_t main(){
    sync;
    ll n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll cnts=0;
    ll mns=0;
    for (int i=0;i<n;i++){
        if (s[i]=='(') cnts++;
        else cnts--;
        mns=min(mns,cnts);
    }
    reverse(s.begin(),s.end());
    for (int i=0;i<-mns;i++) s+='(';
    s+='(';
    s+='@';
    reverse(s.begin(),s.end());
   // cout << s << endl;
    vector <int> bg;
    n=s.size();
    for (int i=1;i<n;i++){
        if (s[i]=='(') {
            if (bg.size()) par[i]=bg.back(),g[bg.back()].pb(i);
            bg.pb(i);
        }
        else bk[i]=bg.back(),bg.pop_back();
      //  cout << bg.size() << endl;
    }
    for (int i=1;i<n;i++){
        if (par[i]!=0){
        //    cout << i << " ekrfn " << par[i] << endl;
        }
    }
    dfs(1,1);
    ll tool=-mns+1;
    for (int i=1;i<=n;i++){
        if (st[i]!=0){
            val[i]=what(g[i].size())+1;
            add(st[i],val[i]);
        }
    }
    for (int i=0;i<N;i++) is[i]=1,len[i]=g[i].size();
    for (int i=1;i<=n;i++){
        if (st[i]!=0) for (int j=0;j<=g[i].size()+2;j++) fe[i].pb(0);
    }
    while(q--){
        ll t;
        cin >> t;
        ll l,r;
        cin >> l >> r;
        l+=tool;
        r+=tool;
        if (t==1){
            ll z=par[l];
           // cout << get(fn[z])-get(st[z]-1) << " " << len[z] << " " << -val[z]+what(len[z]-1)+is[z] << endl;
            add(st[z],-val[z]+what(len[z]-1)+is[z]);
            len[z]--;
            val[z]=what(len[z])+is[z];

            is[l]=0;
            val[l]--;
            add(st[l],-1);

            ll x=lower_bound(g[z].begin(),g[z].end(),l)-g[z].begin();
            x++;
         //   cout << z << " hazf " << val[z] << " " << st[z] << " " << st[l] << " " << fn[z] << " " << get(fn[z])-get(st[z]-1) << " " << get(fn[l])-get(st[l]-1) << endl;
            ad(z,x,1);
        }
        else{
            r=bk[r];
            ll ans=get(fn[r])-get(st[l]-1);
            ll pd=par[l];
         //   cout << l << " " << r << " par " << pd << endl;
            ll x=lower_bound(g[pd].begin(),g[pd].end(),l)-g[pd].begin();
            ll y=lower_bound(g[pd].begin(),g[pd].end(),r)-g[pd].begin();
            x++;
            y++;
          //  cout << ans << " erifn " << endl
            cout << ans+what(y-x+1-(ge(pd,y)-ge(pd,x-1))) << endl;

        }
    }
}