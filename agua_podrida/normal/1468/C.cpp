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

bool comp(pi a, pi b){
  if(a.F > b.F) return true;
  if(a.F == b.F && a.S > b.S) return true;
  return false;
}

int main(){
  int q;
  cin>>q;
  int numCust = 0;
  queue<int> enOrden;
  set<pi> porPlata;
  set<int> atendidos;
  F0(i,q){
    int tipo;
    cin>>tipo;
    if(tipo==1){
      int m;
      cin>>m;
      numCust++;
      enOrden.push(numCust);
      porPlata.insert(mp(-m,numCust));
    }
    else if(tipo==2){
      bool salir = false;
      while(!salir){
        int prox = enOrden.front();
        if(atendidos.count(prox)){
          enOrden.pop();
        }
        else{
          salir = true;
          atendidos.insert(prox);
          cout<<prox<<' ';
          enOrden.pop();
        }
      }
    }
    else{
      bool salir = false;
      while(!salir){
        auto prox = porPlata.begin();
        if(atendidos.count((*prox).S)){
          porPlata.erase(prox);
        }
        else{
          salir = true;
          atendidos.insert((*prox).S);
          cout<<(*prox).S<<' ';
          porPlata.erase(prox);
        }
      }
    }
  }
  cout<<'\n';
}