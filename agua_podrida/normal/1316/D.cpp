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
    ll n,m;
    cin>>n>>m;
    vll a(n);
    F0(i,n) cin>>a[i];
    ll suma = 0;
    F0(i,n) suma += a[i];
    cout<<min(suma,m)<<'\n';
}

void b(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<pair<string,int>> v;
    v.pb(mp(s,1));
    reverse(todo(s));
    v.pb(mp(s,n));
    reverse(todo(s));
    REP(k,2,n-1){
        string t;
        F0(i,n-k+1) t.pb(s[i+k-1]);
        if((n-k+1)%2 == 0){
            F0(i,k-1) t.pb(s[i]);
        }
        else {
            F0(i,k-1) t.pb(s[k-2-i]);
        }
        v.pb(mp(t,k));
    }
    sort(todo(v));
    cout<<v[0].F<<'\n';
    cout<<v[0].S<<'\n';
}

void c(){
    int n,m;
    ll p;
    cin>>n>>m>>p;
    vi a(n);
    vi b(m);
    F0(i,n) cin>>a[i];
    F0(i,m) cin>>b[i];
    int i = 0;
    while(i < n and a[i]%p == 0) i++;
    int j = 0;
    while(j < m and b[j]%p == 0) j++;
    cout<<i+j<<'\n';
}

int n;
void bfs1(vvpi& a, vvc& t, int i, int j, int r, int c){
    if(i == 0 or i == n+1 or j == 0 or j == n+1) return;
    if(a[i][j].F != r or a[i][j].S != c) return;
    if(t[i][j] != '.' and t[i][j] != 'X') return;
    //pongo flecha
    if(t[i][j] == '.'){
        if(i != n and a[i+1][j].F == r and a[i+1][j].S == c and t[i+1][j] != '.') t[i][j] = 'D';
        if(i != 1 and a[i-1][j].F == r and a[i-1][j].S == c and t[i-1][j] != '.') t[i][j] = 'U';
        if(j != n and a[i][j+1].F == r and a[i][j+1].S == c and t[i][j+1] != '.') t[i][j] = 'R';
        if(j != 1 and a[i][j-1].F == r and a[i][j-1].S == c and t[i][j-1] != '.') t[i][j] = 'L';
    }
    //llamo vecinos
    bfs1(a,t,i+1,j,r,c);
    bfs1(a,t,i-1,j,r,c);
    bfs1(a,t,i,j+1,r,c);
    bfs1(a,t,i,j-1,r,c);
}

void apuntenme(vvpi& a, vvc& t, int i, int j){
    if(i != n and a[i+1][j] == mp(-1,-1) and t[i+1][j] == '.') { t[i+1][j] = 'U'; apuntenme(a,t,i+1,j);}
    if(i != 1 and a[i-1][j] == mp(-1,-1) and t[i-1][j] == '.') { t[i-1][j] = 'D'; apuntenme(a,t,i-1,j);}
    if(j != n and a[i][j+1] == mp(-1,-1) and t[i][j+1] == '.') { t[i][j+1] = 'L'; apuntenme(a,t,i,j+1);}
    if(j != 1 and a[i][j-1] == mp(-1,-1) and t[i][j-1] == '.') { t[i][j-1] = 'R'; apuntenme(a,t,i,j-1);}
}

void bfs2(vvpi& a, vvc& t, int i, int j){
    if(i != n and a[i+1][j] == mp(-1,-1)) t[i][j] = 'D';
    else if(j != n and a[i][j+1] == mp(-1,-1)) t[i][j] = 'R';
    else t[i][j] = 'I';
    apuntenme(a,t,i,j);
}

void d(){
    cin>>n;
    vvpi a(n+1,vpi(n+1));
    int r,c;
    F1(i,n) F1(j,n){
        cin>>r>>c;
        a[i][j] = mp(r,c);
    }

    vvc t(n+1,vc(n+1,'.'));
    F1(i,n) F1(j,n){
        if(a[i][j].F == i and a[i][j].S == j) t[i][j] = 'X';
    }

    F1(i,n) F1(j,n) if(t[i][j] == 'X') bfs1(a,t,i,j,i,j);

    F1(i,n) F1(j,n){
        if(t[i][j] == '.' and a[i][j] != mp(-1,-1)){
            cout<<"INVALID\n";
            return;
        }
    }

    F1(i,n) F1(j,n){
        if(a[i][j] == mp(-1,-1) and t[i][j] == '.') bfs2(a,t,i,j);
    }

    F1(i,n) F1(j,n){
        if(t[i][j] == 'I'){
            cout<<"INVALID\n";
            return;
        }
    }

    cout<<"VALID\n";
    F1(i,n){
        F1(j,n) cout<<t[i][j];
        cout<<'\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    d();
    return 0;
}