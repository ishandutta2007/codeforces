#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i(a),_b(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a),_b(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INFLL = 1000000000000000000LL;

int m, mod;
void inc(int& a, int b) { a+=b; if(a>=mod) a-=mod; }
int sum(int a, int b) { a+=b; if(a>=mod) a-=mod; return a; }
int mul(int a, int b) { return ll(a)*b % mod; }
ll n, l,r,u,v;

int f (ll al, ll ar, ll l, ll r, ll a, ll p) {
//  cout<<al<<' '<<ar<<", "<<l<<' '<<r<<"; "<<a<<' '<<p<<endl;
  if(al==l && ar==r) {
    a+=1;
    ll ux = max(0LL, u-a);
    ll vx = v-a;
    if(vx<0) return 0;
    ux = (ux+p-1) / p;
    vx /= p;
//    cout<<ux<<' '<<vx<<endl;
    if(ux>vx) return 0;
    ll k = vx-ux+1;
    int res = p%mod;
    if(k&1) res = mul(res, mul(((k-1)/2)%mod, k%mod));
    else res = mul(res, mul((k/2)%mod, (k-1)%mod));
    inc(res, mul(k%mod, (a+mul(ux%mod, p%mod))%mod));
//    cout<<al<<' '<<ar<<", "<<a<<' '<<p<<": "<<res<<endl;
    return res;
  }
  ll am = (al+ar) / 2;
  int res = 0;
  if(l<=am) inc(res, f(al, am, l, min(r,am), a, p<<1LL));
  if(r>am) inc(res, f(am+1, ar, max(am+1,l), r, a+p, p<<1LL));
  return res;
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  cin>>n>>m>>mod;
  REP(i, m) {
    cin>>l>>r>>u>>v;
    v = min(v, n);
    cout << f(0, n-1, l-1, r-1, 0, 1) << endl;
//    printf("\n\n");
  }
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}