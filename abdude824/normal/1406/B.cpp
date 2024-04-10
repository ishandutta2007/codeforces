#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<pll> vpl;
typedef vector<int> vi;

void solve(){
  int n;
  cin >> n;
  vl a(n); 
  int pos = 0;
  ll best = -1e18;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i] > 0)pos++;
    if(a[i] == 0)best = 0;
  }
  sort(all(a),greater<int>());

  for(int j = 0;j<=5;j++){
    ll p = 1;

    for(int i=0;i<j;i++){
      p*= a[i];
    }
    int falta = 5 - j;
    for(int i = 0;i<falta;i++){
      p*=a[n-1-i];
    }
    best = max(best,p);
  }

  cout << best << endl;
}

int32_t main(){
  FASTIO;
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}