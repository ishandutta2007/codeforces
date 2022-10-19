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
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vbool;
int mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}

template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 100000000
#define todo(v) v.begin(),v.end()

void a(){
    string x;
    string y;
    cin>>x;
    cin>>y;
    reverse(todo(x));
    reverse(todo(y));
    int i = 0;
    while(y[i] != '1') i++;
    int k = 0;
    while(x[i+k] != '1') k++;
    cout<<k<<'\n';
}

void floyd(vvi& grafo){
    F0(k,10){
        F0(i,10){
            F0(j,10){
                mini(grafo[i][j],grafo[i][k]+grafo[k][j]);
            }
        }
    }
}

void b(){
    string s;
    cin>>s;
    int n = s.size();
    vi sint(n);
    F0(i,n){
        sint[i] = (int) s[i] - (int) '0';
    }
    vvi matriz(10, vi(10,0));
    F0(x,10){
        REP(y,x,9){
            vvi grafo(10,vi(10,INF));
            F0(u,10){
                grafo[u][(u+x)%10] = 1;
                grafo[u][(u+y)%10] = 1;
            }
            floyd(grafo);
            int res = 0;
            F0(i,n-1){
                if(grafo[sint[i]][sint[i+1]] > 1000){
                    res = -1;
                    break;
                }
                res += grafo[sint[i]][sint[i+1]]-1;
            }
            matriz[x][y] = res;
            matriz[y][x] = res;
        }
    }
    F0(i,10){
        F0(j,10) cout<<matriz[i][j]<<' ';
        cout<<'\n';
    }
}

int main(){
    b();
    return 0;
}