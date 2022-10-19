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

void c2(){
    int n;
    cin>>n;
    vector<string> a(n);
    F0(i,n) cin>>a[i];
    vi b(3);
    vi c(3);
    F0(i,n) F0(j,n) if(a[i][j] == 'X') b[(i+j)%3]++;
    F0(i,n) F0(j,n) if(a[i][j] == 'O') c[(i+j)%3]++;
    int tokens = 0;
    for(auto x : b) tokens += x;
    for(auto x : c) tokens += x;

    int m1 = 0;
    int m2 = 0;
    while(m1 == m2 or b[m1] + c[m2] > tokens/3){
        m2++;
        if(m2 == 3) {
            m2 = 0;
            m1++;
        }
    }

    F0(i,n) {
        F0(j,n){
            if((i+j)%3 == m1 and a[i][j] == 'X') a[i][j] = 'O';
            if((i+j)%3 == m2 and a[i][j] == 'O') a[i][j] = 'X';
        }
    }

    F0(i,n) cout<<a[i]<<'\n';
}

const int N = 3e5;

char res[N];
int a[N];
int cnt[N+1];

void solve(int l, int r, int m){
    if(l == r) return;
    if(cnt[m] == 0) return;
    res[r-l] = '1';
    if(cnt[m] == 1 and (a[l] == m or a[r] == m)) {
        if(a[l] == m) solve(l+1,r,m+1);
        else solve(l,r-1,m+1);
    }
}

void d(){
    int n;
    cin>>n;
    F0(i,n) cin>>a[i];
    F1(i,n) cnt[i] = 0;
    F0(i,n) cnt[a[i]]++;
    F0(i,n) res[i] = '0';
    solve(0,n-1,1);
    sort(a,a+n);
    bool vale = true;
    F0(i,n) vale &= a[i] == i+1;
    if(vale) res[0] = '1';
    F0(i,n) cout<<res[i];
    cout<<'\n';
}

void f(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vi ap(n+1);
    F0(i,n) ap[a[i]]++;
    int masAp = 0;
    for(auto x : ap) maxi(masAp,x);
    if(masAp > (n+1)/2){
        cout<<"-1\n";
        return;
    }
    vpi seg;
    int l = 0;
    while(l < n){
        int r = l;
        while(r+1 < n and a[r] != a[r+1]) r++;
        seg.pb({l,r});
        l = r+1;
    }
    F1(i,n) ap[i] = 0;
    for(auto p : seg){
        int l = p.first; int r = p.second;
        if(a[l] != a[r]) continue;
        ap[a[l]]++;
        ap[a[r]]++;
    }

    int elquemasAp = 1;
    F1(i,n) if(ap[i] > ap[elquemasAp]) elquemasAp = i;

    int dos = 0;
    int cero = 0;

    for(auto p : seg){
        int l = p.first; int r = p.second;
        if(a[l] == elquemasAp and a[r] == elquemasAp) dos++;
        if(a[l] != elquemasAp and a[r] != elquemasAp) cero++;
    }

    int res = seg.size()-1;

    res += max(0,dos - cero - 1);

    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) f();
    return 0;
}