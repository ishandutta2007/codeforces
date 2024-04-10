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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007
/*
pi dp1[4000001];

void filtrar1(int& dpsize, int res, int e, int i){
    int j2 = 0;
    F0(j,dpsize){
        if(dp[j].second > e) continue;
        if(dp[j].first + (e - dp[j].second) / i < res) continue;
        dp[j2] = dp[j];
        j2++;
    }
    dpsize = j2;
}

void filtrar2(int& dpsize, int res, int e, int i){
    int j2 = 0;
    F0(j,dpsize){
        if(j+1 < dpsize and dp[j].first == dp[j+1].first) continue;
        dp[j2] = dp[j];
        j2++;
    }
    dpsize = j2;
}

bool ord(pi a, pi b) {
    return a > b;
}

void c(){
    int n;
    int e;
    cin>>n>>e;
    vi a(n+1);
    F1(i,n) cin>>a[i];

    int res = 0;
    int i = 0;
    dp[0] = mp(0,0);
    int dpsize = 1;
    int morfo,necesito;


    while(dpsize > 0 and i < n){
        i++;
        int k = dpsize;
        F0(j,k) {
            morfo = dp[j].first;
            dp[j].second += 2;
            necesito = dp[j].second;
            morfo += a[i];
            necesito += i*a[i];
            if(necesito <= e){
                dp[dpsize] = (mp(morfo,necesito));
                dpsize++;
            }
        }
        filtrar1(dpsize,res,e,i);
        sort(dp,dp+dpsize,ord);
        filtrar2(dpsize,res,e,i);

        if(dpsize > 0) maxi(res,dp[0].first);
    }

    cout<<res<<'\n';
}*/

int dp[5000001];

void c2(){
    F0(i,5000001) dp[i] = INF;
    int n,e;
    cin>>n>>e;
    vi a(n+1);
    F1(i,n) cin>>a[i];
    dp[0] = 0;
    int i = 0;
    int res = 0;
    while(i < n){
        i++;
        int j = res;
        while(j >= 0 and j + e/i > res){
            mini(dp[j+a[i]],dp[j]+a[i]*i);
            if(dp[j+a[i]] < e - 2*i) maxi(res,j+a[i]);
            j--;
        }
    }
    cout<<res<<'\n';
}

int n;

pair<vpi,vi> precalcRD(vi& a){
    vi dp = {0};
    vpi res;
    int i = n;
    while(i >= 1){
        if(a[i] > dp.back()) {
            res.pb(mp((int) dp.size(),n+1));
            dp.push_back(a[i]);
        }
        else{
            int lo = 0; // dp[lo] < a[i]
            int hi = dp.size()-1; // dp[hi] > a[i]
            while(lo + 1 != hi){
                int m = (lo+hi)/2;
                if(dp[m] < a[i]) lo = m;
                else hi = m;
            }
            res.pb(mp(hi,dp[hi]));
            dp[hi] = a[i];
        }
        i--;
    }
    res.pb(mp(-1,-1));
    reverse(todo(res));
    return mp(res,dp);
}

pair<vpi,vi> precalcRI(vi& a){
    vi dp = {n+1};
    vpi res;
    int i = n;
    while(i >= 1){
        if(a[i] < dp.back()){
            res.pb(mp((int) dp.size(),0));
            dp.pb(a[i]);
        }
        else {
            int lo = 0; //dp[lo] > a[i]
            int hi = dp.size()-1; //dp[hi] < a[i]
            while(lo+1 != hi){
                int m = (lo+hi)/2;
                if(dp[m] < a[i]) hi = m;
                else lo = m;
            }
            res.pb(mp(hi,dp[hi]));
            dp[hi] = a[i];
        }
        i--;
    }
    res.pb(mp(-1,-1));
    reverse(todo(res));
    return mp(res,dp);
}

int avanzarI(vi& LI, int ai){
    int lo = 0; //LI[lo] < ai
    int hi = n; //LI[hi] > ai
    while(lo+1 != hi){
        int m = (lo+hi)/2;
        if(LI[m] < ai) lo = m;
        else hi = m;
    }
    LI[hi] = ai;
    return hi;
}

int avanzarD(vi& LD, int ai){
    int lo = 0; //LD[lo] > ai
    int hi = n; //LD[hi] < ai
    while(lo+1 != hi){
        int m = (lo+hi)/2;
        if(LD[m] > ai) lo = m;
        else hi = m;
    }
    LD[hi] = ai;
    return hi;
}

int h;

bool hayInterseccion(int a, int b, vi& c, vi& d, int l){
    if(c[0] >= b) return false;
    int lo = 0;// c[lo] < b
    int hi = c.size(); // hi == c.size or c[hi] >= b
    while(lo+1 != hi){
        int m = (lo+hi)/2;
        if(c[m] < b) lo = m;
        else hi = m;
    }
    h = max(a,c[lo]);
    return l > lo and d[l-lo] > a and d[l-lo] > c[lo];
}

vi sacarI(int i, int n, int low, int upp, vi& a){
    a[0] = low-1;
    vi dp = {0};
    vi pred(n+1);
    while(i <= n){
        if(a[i] > upp or a[i] < low) {
            i++;
            continue;
        }
        if(a[i] > a[dp.back()]){
            pred[i] = dp.back();
            dp.pb(i);
        }
        else {
            int lo = 0; //a[dp[lo]] < a[i]
            int hi = dp.size()-1; // a[dp[hi]] > a[i]
            while(lo+1 != hi){
                int m =(lo+hi)/2;
                if(a[dp[m]] < a[i]) lo = m;
                else hi = m;
            }
            pred[i] = dp[lo];
            dp[hi] = i;
        }
        i++;
    }
    vi res;
    int u = dp.back();
    while(u != 0){
        res.pb(u);
        u = pred[u];
    }
    reverse(todo(res));
    return res;
}

vi sacarD(int i, int n, int upp, int low, vi& a){
    a[0] = upp+1;
    vi dp = {0};
    vi pred(n+1);
    while(i <= n){
        if(a[i] < low or a[i] > upp){
            i++;
            continue;
        }
        if(a[i] < a[dp.back()]){
            pred[i] = dp.back();
            dp.pb(i);
        }
        else {
            int lo = 0; // a[dp[lo]] > a[i]
            int hi = dp.size()-1; //a[dp[hi]] < a[i]
            while(lo+1 != hi){
                int m = (lo+hi)/2;
                if(a[dp[m]] > a[i]) lo = m;
                else hi = m;
            }
            pred[i] = dp[lo];
            dp[hi] = i;
        }
        i++;
    }
    int u = dp.back();
    vi res;
    while(u != 0){
        res.pb(u);
        u = pred[u];
    }
    reverse(todo(res));
    return res;
}

void b(){
    cin>>n;
    vi a(n+1);
    F1(i,n) cin>>a[i];

    vi RD,RI;
    vpi modRD,modRI;
    tie(modRD,RD) = precalcRD(a);
    tie(modRI,RI) = precalcRI(a);

    int k = RI.size()-1;
    int l = RD.size()-1;

    if(k + l > n){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    vi LI(n+1,n+1);
    LI[0] = 0;
    vi LD(n+1,0);
    LD[0] = n+1;

    int jli,jld,jri,jrd;
    int i = 1;
    while(i < n-1){
    //avanzar li,ld
        jli = avanzarI(LI,a[i]);
        jld = avanzarD(LD,a[i]);
    //avanzar ri,rd
        RI[modRI[i].first] = modRI[i].second;
        RD[modRD[i].first] = modRD[i].second;
    //ver si hay interseccion
        if(i > 1 and jli > 0 and jli < k and hayInterseccion(LI[jli],RI[k-jli],RD,LD,l)) break;
        if(i > 1 and jld > 0 and jld < l and hayInterseccion(RD[l-jld],LD[jld],LI,RI,k)) break;

        i++;
    }

    if(i == n-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    vi li = sacarI(1,i,1,h,a);
    vi ri = sacarI(i+1,n,h+1,n,a);
    vi ld = sacarD(1,i,n,h+1,a);
    vi rd = sacarD(i+1,n,h,1,a);

    cout<<k<<'\n';
    F0(i,li.size()) cout<<li[i]<<' ';
    F0(i,ri.size()) cout<<ri[i]<<' ';

    cout<<'\n'<<l<<'\n';
    F0(i,ld.size()) cout<<ld[i]<<' ';
    F0(i,rd.size()) cout<<rd[i]<<' ';
    cout<<'\n';
}

void a(){
    string s;
    cin>>s;
    int n = s.size();
    sort(todo(s));
    if(s[0] == '0'){
        int suma = 0;
        F0(i,n) suma += (int) s[i] - (int) '0';
        int i = 1;
        while(i < n and ((int) s[i] - (int) '0') % 2 != 0) i++;
        if(i < n and suma%3 == 0) {
            cout<<"red\n";
            return;
        }
    }
    cout<<"cyan\n";
}

void bb(){
    int n;
    cin>>n;
    ll x;
    while(n--){
        cin>>x;
        if(x >= 14 and x%14 >= 1 and x%14 <= 6) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

void c(){
    int r,c;
    cin>>r>>c;
    if(r*c == 1) {
        cout<<"0\n";
        return;
    }
    if(c == 1){
        F1(i,r) cout<<i+1<<'\n';
        return;
    }
    vvll a(r+1,(vll(c+1)));
    F1(i,r) F1(j,c) a[i][j] = i*(j+r);

    F1(i,r){
        F1(j,c) cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}