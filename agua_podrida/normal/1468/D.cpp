#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vbool;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int i = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second

int main(){
  int t;
  cin>>t;
  while(t--){
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    vi s(m);
    F0(i,m) cin>>s[i];
    sort(s.begin(), s.end());
    int distAPol = abs(a-b) -1;
    int distPolAExtremo = 0;
    if(a < b) distPolAExtremo = b-2;
    else distPolAExtremo = n-b-1;
    int chequeo = distPolAExtremo - distAPol;
    int res = 0;
    F0(i,m){
      chequeo = max(chequeo+1, s[i]);
      if(chequeo > distPolAExtremo) break;
      res++;
    }
    cout<<res<<'\n';

  }
}