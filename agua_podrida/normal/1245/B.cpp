#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e17
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b,a%b);
}

void a(){
    int x,y;
    cin>>x>>y;
    if(gcd(x,y) == 1) cout<<"Finite\n";
    else cout<<"Infinite\n";
}

void b(){
    int r,p,s;
    int n;
    cin>>n;
    cin>>r>>p>>s;
    string ss;
    cin>>ss;
    int victorias = 0;
    vector<char> sec(n,'a');
    F0(i,n){
        if(ss[i] == 'R' and p > 0) {p--; victorias++; sec[i] = 'P';}
        else if(ss[i] == 'P' and s>0) {s--; victorias++;sec[i] = 'S';}
        else if(ss[i] == 'S' and r > 0) { r--; victorias++;sec[i] = 'R';}
    }

    F0(i,n){
        if(sec[i] == 'a'){
            if(r > 0) {sec[i] = 'R'; r--;}
            else if(s > 0) {sec[i] = 'S'; s--;}
            else if(p > 0) {sec[i] = 'P'; p--;}
        }
    }

    if(victorias*2 >= n) {
        cout<<"YES\n";
        F0(i,n) cout<<sec[i];
        cout<<'\n';
    }
    else cout<<"NO\n";
}

void c(){
    string s;
    cin>>s;
    int n = s.size();
    vll fib(n+1);
    fib[0] = 1;
    fib[1] = 1;
    REP(i,2,n){
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= mod;
    }

    ll posibles = 1;
    F0(i,n){
        if(s[i] == 'm' or s[i] == 'w') {
            cout<<"0\n";
            return;
        }
        if(s[i] == 'u' or s[i] == 'n'){
            int j = i;
            while(j < n and s[j] == s[i]) j++;
            int apariciones = j-i;
            posibles *= fib[apariciones];
            posibles %= mod;
            i = j-1;
        }
    }

    cout<<posibles<<'\n';
}

int main() {
    int t;
    cin>>t;
    while(t--) b();
    return 0;
}