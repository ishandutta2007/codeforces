#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 9223372036854775;

pll a[MAXN];
ll s[MAXN];

vector<ll> g[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, u, v;
    cin >> n;
    for(int i =0;i<n-1;i++){
        cin >> u >> v;
        if(max(u, v)!=n){
            cout << "NO";
            return 0;
        }
        if(u==v){
            cout << "NO";
            return 0;
        }
        s[min(u,v)-1]++;
    }
    ll f = 1;
    for(int i =0;i<n-1;i++){
        if(s[i]!=0) g[i].pb(i+1);
        for(int j =0;j<s[i]-1;j++){
            while(s[f-1]!=0)f++;
            g[i].pb(f);
            f++;
        }
        if(f-1 > i+1){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0;i<n;i++){
        if(g[i].size()>=1){
            cout << g[i].back() << " " << n << endl;
        }
        //debug(i);
        //debug(g[i].size());

        for(int j = 0;j<g[i].size()-1;j++){
            if(g[i].size()<=1)break;
            cout << g[i][j] << " " << g[i][j+1] << endl;
        }
    }
    return 0;

}