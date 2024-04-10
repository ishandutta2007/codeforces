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
  int n;
  cin>>n;
  vi a(n);
  F0(i,n) cin>>a[i];
  set<int> vistos;
  map<int, int> numAindex;
  vi proxMayor(n, -1);
  F0(i,n){
    numAindex[a[i]] = i;
  }

  F0(i,n){
    if(vistos.size()==0){
      vistos.insert(a[i]);
      continue;
    }
    auto it = vistos.lower_bound(a[i]);
    if(it == vistos.begin()){
      if((*it) < a[i]){
        proxMayor[numAindex[(*it)]] = i;
        vistos.erase((*it));
      }
      vistos.insert(a[i]);
    }
    else{
      if(vistos.size() >= 1){
        it--;
        proxMayor[numAindex[(*it)]] = i;
        vistos.erase((*it));
        vistos.insert(a[i]);
      }
    }
  }

  //F0(i,n){
  //  cout<<proxMayor[i]<<'\n';
  //}

  vvi res;
  vector<bool> tocados(n, false);
  F0(i,n){
    if(tocados[i]) continue;
    tocados[i] = true;
    vi nuevo;
    int index = i;
    while(index != -1){
      tocados[index] = true;
      nuevo.pb(a[index]);
      index = proxMayor[index];
    }
    res.pb(nuevo);
  }

  F0(i, res.size()){
    F0(j, res[i].size()){
      cout<<res[i][j]<<' ';
    }
    cout<<'\n';
  }
}