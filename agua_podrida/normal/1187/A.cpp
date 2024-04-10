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

void b(){

}

void c(){

}

void d(){

}

void e(){

}

void f(){

}

int main(){
    int t;
    cin>>t;
    while(t--) a();
    return 0;
}