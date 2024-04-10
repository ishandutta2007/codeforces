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
#define INF 1000000000
#define todo(v) v.begin(),v.end()

void a(){
    int n,s,t;
    cin>>n>>s>>t;
    int st = s+t-n;
    s -= st;
    t -= st;
    cout<<max(1,max(s,t)+1)<<'\n';
}

bool sePuede(vvi& apariciones, vi& aT, int mid){
    if (mid == 0)
        return false;
    F0(i,26) if(apariciones[i][mid-1] < aT[i]) return false;
    return true;
}

void b(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vvi aparicionesEnPrefijoPorLetra(26,vi(n,0));
    F0(i,n){
        int pos = (int) s[i] - (int)'a';
        aparicionesEnPrefijoPorLetra[pos][i]++;
    }
    F1(i,n-1){
        F0(j,26){
            aparicionesEnPrefijoPorLetra[j][i] += aparicionesEnPrefijoPorLetra[j][i-1];
        }
    }
    int m;
    cin>>m;
    string t;
    F0(i,m){
        cin>>t;
        vi aT(26);
        F0(j,t.size()){
            int pos = (int) t[j] - (int)'a';
            aT[pos]++;
        }
        int lo = 0;
        int hi = n;
        while(lo+1 != hi){
            int mid = (lo+hi)/2;
            if(sePuede(aparicionesEnPrefijoPorLetra,aT,mid)) hi = mid;
            else lo = mid;
        }
        cout<<hi<<'\n';
    }
}

void c(){
    int n,m;
    cin>>n>>m;
    int t,l,r;
    vpi desordenados;
    vbool crece(n+1,false);
    F0(i,m){
        cin>>t>>l>>r;
        if(t == 1) {
            for(int k = l+1; k <= r; k++) crece[k] = true;
        }
        else desordenados.pb(mp(l,r));
    }
    bool sePuede = true;
    F0(i,desordenados.size()){
        bool creciente = true;
        REP(k,desordenados[i].F+1,desordenados[i].S) if(!crece[k]) creciente = false;
        if(creciente) sePuede = false;
    }

    if(sePuede){
        cout<<"YES\n";
        int i = 1;
        int num = 2000;
        while(i <= n){
            if(!crece[i]){
                num--;
                cout<<num<<' ';
                i++;
            }
            else {
                num++;
                cout<<num<<' ';
                i++;
            }
        }
        cout<<'\n';
    }
    else cout<<"NO\n";
}

void d(){

}

void e(){

}

void f(){

}

int main(){
    c();
    return 0;
}