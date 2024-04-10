#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
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
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const ll mod = 1000000007;
const ll INF  = 1e18;
const double eps = 0.00000001;

int n;
string s;

void e(){
    cin>>s;
    n = s.size();
    sort(todo(s));
    if(s[0] == s.back()) {
        cout<<s<<'\n';
        return;
    }
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n and s[i] == s[j]) j++;
        if(i+1 == j){
            char aux = s[i];
            s[i] = 'a';
            sort(todo(s));
            s[0] = aux;
            cout<<s<<'\n';
            return;
        }
        i = j;
    }

    i = 0;
    int j = 0;
    while(s[i] == s[j]) j++;
    if(j >= 2 and j-2 <= (n-2)/2){
        string t;
        t += s[0];
        t += s[1];
        i = 2;
        while(s[i] == s[0] and j < n){
            t += s[j], j++;
            t += s[i], i++;
        }
        while(j < n) t += s[j], j++;
        cout<<t<<'\n';
        return;
    }
    if(s.back() != s[j]){
        int k = j;
        while(s[k] == s[j]) k++;
        string t;
        t += s[i], i++;
        t += s[j], j++;
        while(s[i] == s[0]) t += s[i], i++;
        t += s[k];
        while(j < n){
            if(j != k) t += s[j];
            j++;
        }
        cout<<t<<'\n';
        return;
    }
    string t;
    t += s[i], i++;
    while(j < n) t += s[j], j++;
    while(s[i] == s[0]) t += s[i], i++;
    cout<<t<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) e();
    return 0;
}