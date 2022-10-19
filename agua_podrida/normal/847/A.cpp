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
  int n; cin>>n;
  vi l(n+1);
  vi r(n+1);
  F1(i,n){
    cin>>l[i]>>r[i];
  }
  vi comienzos;
  F1(i,n){
    if(l[i]==0) comienzos.pb(i);
  }
  if(comienzos.size() > 1){
    int index = comienzos[0];
    int k = 0;
    int visitados = 1;
    while(visitados < n){
      if(r[index]==0){
        k++;
        r[index] = comienzos[k];
        l[comienzos[k]] = index;
      }
      //cout<<"AAA"<<endl;
      index = r[index];
      visitados++;
    }
  }
  F1(i,n){
    cout<<l[i]<<' '<<r[i]<<'\n';
  }
}