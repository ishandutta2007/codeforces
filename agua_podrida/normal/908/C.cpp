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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    string s;
    cin>>s;
    int res = 0;
    for(auto c : s){
        if(c == 'a') res++;
        if(c == 'e') res++;
        if(c == 'i') res++;
        if(c == 'o') res++;
        if(c == 'u') res++;
        if(c == '1') res++;
        if(c == '3') res++;
        if(c == '5') res++;
        if(c == '7') res++;
        if(c == '9') res++;
    }
    cout<<res<<'\n';
}

int xo,yo;
int n,m;


bool piola(vector<string>& t, string trad, string& s){
    int x = xo;
    int y = yo;
    F0(i,s.size()){
        char c = trad[s[i] - '0'];
        if(c == 'N') {
            if(y == 0 or t[x][y-1] == '#') return false;
            y--;
        }
        if(c == 'S'){
            if(y+1 == m or t[x][y+1] == '#') return false;
            y++;
        }
        if(c == 'E'){
            if(x+1 == n or t[x+1][y] == '#') return false;
            x++;
        }
        if(c == 'W'){
            if(x == 0 or t[x-1][y] == '#') return false;
            x--;
        }
        if(t[x][y] == 'E') return true;
    }
    return false;
}

void b(){
    cin>>n>>m;
    vector<string> t(n);
    F0(i,n) cin>>t[i];
    F0(i,n) F0(j,m) if(t[i][j] == 'S') xo = i, yo = j;
    string s;
    cin>>s;
    int res = 0;
    string trad = "ENSW";
    do {
        if(piola(t,trad,s)) res++;
    } while(next_permutation(todo(trad)));
    cout<<res<<'\n';
}

void c(){
    int n;
    double r;
    cin>>n>>r;
    vector<double> x(n);
    F0(i,n) cin>>x[i];

    vector<double> res(n,r);
    F0(i,n){
        F0(j,i){
            double dx = abs(x[j]-x[i]);
            if(dx > 2*r) continue;
            if(dx == 2*r) {
                maxi(res[i],res[j]);
                continue;
            }
            double dy = sqrt(4*r*r - dx*dx);
            maxi(res[i],res[j]+dy);
        }
    }

    F0(i,n) cout<<setprecision(9)<<fixed<<res[i]<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}