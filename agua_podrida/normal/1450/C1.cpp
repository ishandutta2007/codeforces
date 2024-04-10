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
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

void a(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    sort(todo(s));
    cout<<s<<'\n';
}

void b(){
    int n,k;
    cin>>n>>k;
    vi x(n),y(n);
    F0(i,n) cin>>x[i]>>y[i];
    F0(i,n){
        bool todoCerca = true;
        F0(j,n) if(abs(x[i]-x[j]) + abs(y[i]-y[j]) > k) todoCerca = false;
        if(todoCerca) {
            cout<<"1\n";
            return;
        }
    }
    cout<<"-1\n";
}

void c1(){
    int n;
    cin>>n;
    vector<string> a(n);
    F0(i,n) cin>>a[i];
    vi b(3);
    F0(i,n) F0(j,n) if(a[i][j] == 'X') b[(i+j)%3]++;
    int m = 0;
    if(b[1] < b[0]) m = 1;
    if(b[2] < b[m]) m = 2;

    F0(i,n) F0(j,n) if((i+j)%3 == m and a[i][j] == 'X') a[i][j] = 'O';

    F0(i,n) cout<<a[i]<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) c1();
    return 0;
}