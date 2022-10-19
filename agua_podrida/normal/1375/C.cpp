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
#define INF 1e12
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    F0(i,n){
        if(i % 2) a[i] = abs(a[i]);
        else a[i] = -abs(a[i]);
    }
    F0(i,n) cout<<a[i]<<' ';
    cout<<'\n';
}

void b(){
    int n,m;
    cin>>n>>m;
    vvi a(n,vi(m));
    F0(i,n) F0(j,m) cin>>a[i][j];

    if(a[0][0] > 2 or a[n-1][0] > 2 or a[0][m-1] > 2 or a[n-1][m-1] > 2){
        cout<<"NO\n";
        return;
    }
    F0(i,n){
        if(a[i][0] > 3 or a[i][m-1] > 3){
            cout<<"NO\n";
            return;
        }
    }
    F0(j,m){
        if(a[0][j] > 3 or a[n-1][j] > 3){
            cout<<"NO\n";
            return;
        }
    }

    F0(i,n) F0(j,m){
            if(a[i][j] > 4){
                cout<<"NO\n";
                return;
            }
        }

    cout<<"YES\n";

    F0(i,n){
        F0(j,m){
            if((i == 0 or i == n-1) and (j == 0 or j == m-1)) cout<<2;
            else if(i == n-1 or i == 0 or j == 0 or j == m-1) cout<<3;
            else cout<<4;
            cout<<' ';
        }
        cout<<'\n';
    }
}

void d(){
    int n;
    cin>>n;
    vi a(n+1);
    F1(i,n) cin>>a[i];

    set<int> libres;
    vi cant(n+1);
    F1(i,n) cant[a[i]]++;
    F0(i,n+1) if(cant[i] == 0) libres.insert(i);

    vi res;
    F1(i,n){
        if(a[i] == i-1) continue;
        REP(j,i+1,n){
            if(a[j] == i-1){
                res.pb(j);
                cant[a[j]]--;
                auto it = libres.begin();
                if(cant[a[j]] == 0) libres.insert(a[j]);
                a[j] = *it;
                libres.erase(a[j]);
                cant[a[j]]++;
            }
        }
        res.pb(i);
        cant[a[i]]--;
        auto it = libres.begin();
        if(cant[a[i]] == 0) libres.insert(a[i]);
        a[i] = *it;
        libres.erase(a[i]);
        cant[a[i]]++;
    }

    cout<<res.size()<<'\n';
    F0(i,res.size()) cout<<res[i]<<' ';
    cout<<'\n';
}

void c(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    if(a[0] < a[n-1]) cout<<"YES\n";
    else cout<<"NO\n";
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