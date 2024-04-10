#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

char c[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    str s, s2;
    cin >> t;
    while(t--){
      cin >> s;
      ll n = s.size();
      for(int i = 0; i < n; i++)c[i] = s[i];
      sort(c, c + n);
      s2 = "";
      for(int i = 0; i<n;i++) s2+= c[i];
      //sort(s, s + (int) s.size());
      cout << (c[0] == c[s.size() - 1] ? "-1" : s2) << '\n';
    }
    return 0;
}