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
#define INF 10000000
#define todo(v) v.begin(),v.end()

void a(){
    string s;
    cin>>s;
    int n = s.size();
    bool ocupadoVertical = false;
    bool ocupadoHorizontal = false;
    F0(i,n){
        if(s[i] == '0'){
            if(ocupadoVertical){
                ocupadoVertical = false;
                cout<<"3 1\n";
            }
            else{
                ocupadoVertical = true;
                cout<<"1 1\n";
            }
        }
        else {
            if(ocupadoHorizontal){
                ocupadoHorizontal = false;
                cout<<"4 1\n";
            }
            else{
                ocupadoHorizontal = true;
                cout<<"4 3\n";
            }
        }
    }
}

void b(){
    char aux;
    cout<<"? 0 1"<<endl;
    cin>>aux;
    if(aux == 'x') {
        cout<<"! 1"<<endl;
        return;
    }
    //busco rango (n,2n]
    ll x = 1;
    ll y = 2;
    do {
        cout<<"? "<<x<<' '<<y<<endl;
        x *= 2;
        y *= 2;
        cin>>aux;
    } while(aux == 'y');
    ll lo = x/2;
    ll hi = x;
    while(lo + 1 != hi){
        ll mid = (lo+hi)/2;
        cout<<"? "<<lo<<' '<<mid<<endl;
        cin>>aux;
        if(aux == 'y') lo = mid;
        else hi = mid;
    }
    cout<<"! "<<hi<<endl;
}

int main(){
    string s;
    cin>>s;
    while(s == "start"){
        b();
        cin>>s;
    }
    return 0;
}