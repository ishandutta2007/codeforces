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
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 998244353;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    string res;
    while(n >= 4){
        res.pb('1');
        n -= 2;
    }
    if(n == 2) res.pb('1');
    else res.pb('7');

    F0R(i,res.size()) cout<<res[i];
    cout<<'\n';
}

void b(){
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    vi suma(2*n);
    int total = 0;
    F0(i,n) {
        suma[total+n]++;
        if(s[i] == '1') total--;
        else total++;
    }

    if(total == 0){
        total = 0;
        F0(i,n){
            if(total == x) {
                cout<<"-1\n";
                return;
            }
            if(s[i] == '1') total--;
            else total++;
        }
    }

    // invierto tod o para que total > 0
    if(total < 0){
        F1(i,n) swap(suma[i],suma[2*n-i]);
        total = -total;
        x = -x;
    }

    int aux = x;
    if(x < -n){
        cout<<"0\n";
        return;
    }

    int res = 0;
    x %= total;
    x += total;
    x %= total;
    for(int i = x; i < n and i <= aux; i += total) res += suma[n+i];
    for(int i = x-total; i > -n and i <= aux; i -= total) res += suma[n+i];
    cout<<res<<'\n';
}

void c(){
    string s;
    string t;
    cin>>s>>t;
    map<char,set<int>> coso;
    F0(i,s.size()) coso[s[i]].insert(i);
    int res = 1;
    int i = 0;
    int j = -1;
    auto it = coso[t[0]].end();
    while(i < t.size()){
        if(coso[t[i]].empty()){
            cout<<"-1\n";
            return;
        }

        it = coso[t[i]].upper_bound(j);
        if(it != coso[t[i]].end() and *it < s.size()) {
            j = *it;
            i++;
        }
        else {
            j = -1;
            res++;
        }
    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) c();
    return 0;
}