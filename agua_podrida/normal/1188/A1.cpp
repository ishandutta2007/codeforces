#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vbool;
typedef unsigned int uint;

#define eb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 10000000

#define V 60

void a(){
    int n;
    cin>>n;
    vector<int> grado(n+1,0);
    int aux;
    F0(i,n-1) {
        cin>>aux;
        grado[aux]++;
        cin>>aux;
        grado[aux]++;
    }
    F1(i,n){
        if(grado[i] == 2){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

void b(){

}

int main(){
    a();
    return 0;
}