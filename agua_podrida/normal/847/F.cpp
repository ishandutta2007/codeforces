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
#define eps 0.000000001
#define PI acos(-1.0)

void f(){
    int n,k,m,a,g;
    cin>>n>>k>>m>>a;
    vi last(n,-1),cnt(n);

    F0(i,a) {
        cin>>g;
        g--;
        cnt[g]++;
        last[g] = i;
    }
    if(n == 1) {
        cout<<"1\n";
        return;
    }
    vi res(n);
    F0(i,n){
        if(cnt[i] == 0 and m == a) {
            res[i] = 3;
            continue;
        }
        int mejores = 0;
        F0(j,n){
            if(i == j) continue;
            if(m != a and cnt[j] >= cnt[i] + m-a) mejores++;
            if(cnt[j] == cnt[i] and m == a and last[j] < last[i]) mejores++;
            if(m == a and cnt[j] > cnt[i]) mejores++;   
        }
        if(mejores >= k) res[i] = 3;
    }
    F0(i,n){
        if(res[i] == 3) continue;
        if(cnt[i] == 0){
            res[i] = 2;
            continue;
        }
        vi lesFalta;
        int mejores = 0;
        F0(j,n) {
            if(i == j) continue;
            if(cnt[j] < cnt[i]) lesFalta.pb(cnt[i]-cnt[j]+1);
            else if(cnt[j] == cnt[i] and last[j] > last[i]) lesFalta.pb(1);
            else mejores++;
        }
        sort(todo(lesFalta));
        reverse(todo(lesFalta));
        int sobran = m-a;
        while(!lesFalta.empty() and sobran >= lesFalta.back()){
            mejores++;
            sobran -= lesFalta.back();
            lesFalta.pop_back();
        }
        if(mejores >= k) res[i] = 2;
        else res[i] = 1;
    }
    F0(i,n-1) cout<<res[i]<<' ';
    cout<<res[n-1];
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../evolution/evolution-11-common-endings.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    f();
    return 0;
}