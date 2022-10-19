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
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 2e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define mod 1000000007

int preg(int i){
    cout<<"? "<<i<<'\n';
    int res;
    cin>>res;
    return res;
}

void a(){
    int n;
    cin>>n;
    if(n == 1){
        cout<<"! 1\n";
        return;
    }

    if(n <= 100){
        vi a(n+2);
        a[0] = INF;
        a[n+1] = INF;
        F1(i,n) {
            cout<<"? "<<i<<'\n';
            cin>>a[i];
        }
        F1(i,n){
            if(a[i] < min(a[i-1],a[i+1])){
                cout<<"! "<<i<<'\n';
                return;
            }
        }
    }

    vi a(n+2);
    a[0] = INF;
    a[n+1] = INF;

    a[1] = preg(1);
    a[2] = preg(2);
    if(a[1] < a[2]) {
        cout<<"! 1\n";
        return;
    }
    a[n] = preg(n);
    a[n-1] = preg(n-1);
    if(a[n] < a[n-1]) {
        cout<<"! "<<n<<'\n';
        return;
    }

    int lo = 2;
    int hi = n-1;
    while(lo < hi){
        int m = (lo+hi)/2;
        if(1 <= m and m <= n) a[m] = preg(m);
        if(1 <= m-1 and m-1 <= n) a[m-1] = preg(m-1);
        if(1 <= m+1 and m+1 <= n) a[m+1] = preg(m+1);
        if(a[m] < min(a[m-1],a[m+1])){
            cout<<"! "<<m<<'\n';
            return;
        }
        if(a[m] > a[m-1]) hi = m-1;
        else lo = m+1;
    }
    REP(i,lo-2,lo+2){
        if(i <= 0 or i > n) continue;
        if(a[i] != 0 and a[i] < min(a[i-1],a[i+1])){
            cout<<"! "<<i<<'\n';
            return;
        }
    }
}

int main(){
    a();
}