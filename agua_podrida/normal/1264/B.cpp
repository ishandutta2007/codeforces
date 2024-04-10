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

void b(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a == 0 and b == 0 and c+1 == d){
        cout<<"YES\n";
        cout<<"3 ";
        while(c--) cout<<"2 3 ";
        cout<<'\n';
        return;
    }
    if(a == b+1 and c == 0 and  d == 0){
        cout<<"YES\n";
        cout<<"0 ";
        while(b--) cout<<"1 0 ";
        cout<<'\n';
        return;
    }
    if(d > c or a > b) {
        cout<<"NO\n";
        return;
    }
    vi res;
    while(a > 0){
        res.pb(0); res.pb(1);
        a--; b--;
    }

    while(d > 0){
        res.pb(2); res.pb(3);
        c--; d--;
    }

    while(c > 0 and b > 0){
        res.pb(2); res.pb(1);
        c--; b--;
    }

    if(c == 1 and b == 0) {
        res.pb(2);
        cout<<"YES\n";
        F0(i,res.size()-1) cout<<res[i]<<' ';
        cout<<res.back();
        cout<<'\n';
    }
    else if(b == 1 and c == 0) {
        cout<<"YES\n";
        reverse(todo(res));
        res.pb(1);
        reverse(todo(res));
        F0(i, res.size()-1) cout << res[i] << ' ';
        cout<<res.back();
        cout << '\n';
    }
    else if(b == 0 and c == 0){
        cout<<"YES\n";
        F0(i, res.size()-1) cout << res[i] << ' ';
        cout<<res.back();
        cout << '\n';
    }
    else {
        cout<<"NO\n";
    }
}

void e(){
    clock_t begin = clock();
    srand(time(NULL));
    int n,m;
    cin>>n>>m;
    vvb a(n,vb(n,false));
    vvb res(n,vb(n,false));
    set<pi> aristasDecido;
    F0(i,n){
        REP(j,i+1,n-1){
            aristasDecido.insert(mp(i,j));
        }
    }
    int u,v;
    F0(i,m){
        cin>>u>>v;
        u--; v--;
        a[u][v] = true;
        aristasDecido.erase(mp(min(u,v),max(u,v)));
    }

    int mejor = 0;
    vpi aristas;
    forall(it,aristasDecido) aristas.pb(*it);
    double tiempo = 0.0;
    while(tiempo < 0.9){
        F0(i,aristas.size()){
            int x = rand()%2;
            if(x){
                a[aristas[i].F][aristas[i].S] = true;
                a[aristas[i].S][aristas[i].F] = false;
            }
            else {
                a[aristas[i].S][aristas[i].F] = true;
                a[aristas[i].F][aristas[i].S] = false;
            }
        }

        int cantTriplas = 0;
        F0(i,n){
            F0(j,n){
                if(i == j) continue;
                F0(k,n){
                    if(a[i][k] and a[k][j] and a[j][i]) cantTriplas++;
                    if(a[k][i] and a[j][k] and a[i][j]) cantTriplas++;
                }
            }
        }

        bool mejoro = true;
        while(mejoro){
            mejoro = false;
            random_shuffle(todo(aristas));
            F0(i,aristas.size()){
                u = aristas[i].F;
                v = aristas[i].S;
                int uv = 0;
                int vu = 0;
                F0(k,n){
                    if(a[u][k] and a[k][v]) vu++;
                    if(a[v][k] and a[k][u]) uv++;
                }
                if(uv > vu and a[v][u]){
                    cantTriplas += uv - vu;
                    a[v][u] = false;
                    a[u][v] = true;
                    mejoro = true;
                    break;
                }
                if(vu > uv and a[u][v]){
                    cantTriplas += vu - uv;
                    a[v][u] = true;
                    a[u][v] = false;
                    mejoro = true;
                    break;
                }
            }
        }
        if(cantTriplas > mejor) {
            res = a;
            mejor = cantTriplas;
        }
        clock_t end = clock();
        tiempo = double(end - begin) / CLOCKS_PER_SEC;
    }

    F0(i,n) {
        F0(j,n)cout<<res[i][j];
        cout<<'\n';
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    b();
    return 0;
}