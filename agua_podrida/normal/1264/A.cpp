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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];

    sort(todo(a));
    reverse(todo(a));
    int g = 0,s = 0,b = 0;
    F1(i,n-1){
        g++;
        if(a[i] != a[i-1]){
            break;
        }
    }
    if((g+g+1+g+1)*2 > n) {
        cout<<"0 0 0\n";
        return;
    }

    REP(i,g+1,n-1){
        s++;
        if(a[i] != a[i-1] and s > g){
            break;
        }
    }

    if((g+s+g+1)*2 > n) {
        cout<<"0 0 0\n";
        return;
    }

    int bres = 0;
    REP(i,g+s+1,n-1){
        b++;
        if(2*s+2*g+2*b > n) break;
        if(a[i] != a[i-1] and b > g) {
            bres = b;
        }
    }

    if(bres == 0){
        cout<<"0 0 0\n";
        return;
    }
    cout<<g<<' '<<s<<' '<<bres<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) a();
    return 0;
}