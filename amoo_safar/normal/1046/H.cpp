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

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;

str a[MAXN];
ll b[MAXN][26];
ll p2[26];
map<ll, ll> ma;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    p2[0] = 1;
    for(int i = 1;i<26;i++)p2[i] = p2[i-1] * 2;
    ll n;
    cin >> n;
    //ll ans = 0;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<a[i].size();j++){
            b[i][a[i][j]-'a'] = 1 - b[i][a[i][j]-'a'];
        }
    }
    ll ans = 0,nu;
    for(int i =0;i<n;i++){
        nu = 0;
        for(int j = 0;j<26;j++) nu += (b[i][j]*p2[j]);
        ma[nu] ++;
    }
    for(int i =0;i<n;i++){
        nu = 0;
        for(int j = 0;j<26;j++) nu += (b[i][j]*p2[j]);
        ans += ma[nu];
        for(int j = 0;j<26;j++){
            if(b[i][j] == 0) ans += ma[nu+p2[j]];
            else ans += ma[nu-p2[j]];
        }
    }
    cout << (ans-n)/2 << endl;
    return 0;

}