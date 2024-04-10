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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

bool cierra(pi& p){
    if(p.S > 0) return false;
    p.S = -p.S;
    return true;
}

vi quitar(vi a, int x){
    int i = 0;
    while(i < a.size() and a[i] != x) i++;
    if(i < a.size()){
        a[i] = a.back();
        a.pop_back();
    }
    return a;
}

int n,m,k;

bool isOK(int mask, vi& usando){
    F0(i,k) if((mask & (1<<i) and usando[i] == 0)) return false;
    return true;
}

void happyNewYear(){
    cin>>n>>m>>k;
    vi lo(n+1);
    vi hi(n+1);
    F1(i,n){
        cin>>lo[i]>>hi[i];
        hi[i]++;
    }

    vpi events;
    F1(i,n){
        events.pb(mp(lo[i],i));
        events.pb(mp(hi[i],-i));
    }
    sort(todo(events));

    vi dp(1<<k);
    vi usando(k);
    F0(i,2*n){
        vi dp1(1<<k);
        pi e = events[i];
        if(cierra(e)){
            int inter = e.second;
            int j = 0;
            while(usando[j] != inter) j++;
            F0(mask,1<<k){
                if(!isOK(mask,usando)) continue;
                maxi(dp1[mask & (~(1<<j))], dp[mask]);
            }
            usando[j] = 0;

            int l = e.first;
            int r = l;
            if(i+1 < 2*n) r = events[i+1].first;
            F0(mask,1<<k){
                if(!isOK(mask,usando)) continue;
                int bits = 0;
                F0(j,k) if(mask & (1<<j)) bits++;
                if(bits % 2 == 1) dp1[mask] += r-l;
            }
        }
        else {
            int inter = e.second;
            int j = 0;
            while(usando[j] != 0) j++;
            F0(mask,1<<k){
                if(!isOK(mask,usando)) continue;
                dp1[mask|(1<<j)] = dp[mask];
                dp1[mask] = dp[mask];
            }
            usando[j] = inter;
            int l = e.first;
            int r = l;
            if(i+1 < 2*n) r = events[i+1].first;
            F0(mask,1<<k){
                if(!isOK(mask,usando)) continue;
                int bits = 0;
                F0(j,k) if(mask & (1<<j)) bits++;
                if(bits % 2 == 1) dp1[mask] += r-l;
            }
        }
        dp = dp1;
    }
    int res = 0;
    F0(mask,1<<k) maxi(res,dp[mask]);
    cout<<res<<'\n';
}

void roadTo1600(){
    int n;
    cin>>n;
    if(n <= 2){
        cout<<"-1\n";
        return;
    }
    int num = 1;
    vvi res(n,vi(n));
    int i = 0; int j = 0;
    if(n%2 == 1 and n > 3) {
        i = n-1;
        j = n-1;
        while(j >= 0 and res[i][j] == 0){
            res[i][j] = num;
            num++;
            j--;
        }
        j++;
        i--;
        while(i >= 0 and res[i][j] == 0) {
            res[i][j] = num;
            num++;
            i--;
        }
        i++;
        j++;
    }
    while(num <= n*n-9){
        while(j < n and res[i][j] == 0){
            res[i][j] = num;
            j++;
            num++;
        }
        i++;
        j--;
        while(i < n and res[i][j] == 0){
            res[i][j] = num;
            i++;
            num++;
        }
        i--;
        j--;
        if(num > n*n-9) break;
        while(j >= 0 and res[i][j] == 0){
            res[i][j] = num;
            num++;
            j--;
        }
        j++;
        i--;
        while(i >= 0 and res[i][j] == 0) {
            res[i][j] = num;
            num++;
            i--;
        }
        i++;
        j++;
    }
    if(n == 3){
        i = n-1;
        j = n-1;
    }
    res[i-2][j-2] = num+8; res[i-2][j-1] = num+5; res[i-2][j] = num+6;
    res[i-1][j-2] = num+3; res[i-1][j-1] = num+2; res[i-1][j] = num+7;
    res[i][j-2] = num+4; res[i][j-1] = num+1; res[i][j] = num;

    F0(i,n){
        F0(j,n) cout<<res[i][j]<<' ';
        cout<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../c2.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    roadTo1600();
    return 0;
}