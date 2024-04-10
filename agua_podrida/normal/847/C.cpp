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
  //usar ll!!!
  ll n, k;
  cin>>n>>k;
  ll max = ((n-1)*n)/2;
  if(k > max){
    cout<<"Impossible\n";
    return 0;
  }

  string res;
  int abiertos = 0;
  while(n>0 && k >0){
    if(abiertos <= k){
      k -= abiertos;
      res.pb('(');
      abiertos++;
      n--;
    }
    else{
      res.pb(')');
      abiertos--;
    }
  }
  while(abiertos > 0){
    res.pb(')');
    abiertos--;
  }
  while(n > 0){
    res.pb('(');
    res.pb(')');
    n--;
  }
  cout<<res<<'\n';

}