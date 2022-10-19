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
const int N=1e5+100;
vector <int> c[26];
ll fen[N];
void add(ll idx,ll val){
    for (;idx<N;idx+=idx & (-idx)) fen[idx]+=val;
}
ll get(ll idx){
    ll s=0;
    for (;idx;idx-=idx & (-idx)){
        s+=fen[idx];
    }
    return s;
}
int Main(){
    for (int i=0;i<26;i++) c[i].clear();
    string s,t;
    ll n;
    cin >> n;
    cin >> s >> t;
    ll ans=(ll)1e12;
    for (int i=1;i<=n;i++){
        c[s[i-1]-'a'].pb(i);
    }
    for (int i=0;i<26;i++) reverse(c[i].begin(),c[i].end());
    ll cnt=0;
    for (int i=1;i<=n;i++){
        ll jav=cnt+(ll)1e12;
        //cout << i << " " << cnt << endl;
        for (int j=0;j<26;j++){
            if (j>=t[i-1]-'a') break;
            if (c[j].size()){
               // if (s[0]=='c' && i==2)
                jav=min(jav,cnt+c[j].back()-1-get(c[j].back()));
            }
        }
        ans=min(ans,jav);
        ll z=t[i-1]-'a';
        if (c[z].size()==0) break;
       // cout << cnt << " hey " << c[z].back() << " " << ans  << endl;
        cnt+=c[z].back()-1-get(c[z].back());
        add(c[z].back(),1);
        c[z].pop_back();
    }
   // cout << ans << " ans " << endl;
    for (int i=1;i<=n;i++) if (get(i)) add(i,-1);
    if (ans==(ll)1e12) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}