#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx,avx2")

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define dbg(x) cerr<<#x<<" : "<<x<<endl

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;
const ll INF = 1e18+1;
const ll MOD = 1000000007L;
clock_t time_p=clock();
void timer(){time_p=clock()-time_p;cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";}

template <typename Arg1> ostream& operator << (ostream& out, const vector<Arg1> &a) {out<<"[ ";for(const auto &x:a)out<<x<<" ";return out<<"]";}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,d;
    cin>>n>>d;
    vi a(n+1);//1based
    rep(i,n) cin>>a[i+1];
    long double dp[n+1][10];
    ll bt[n+1][10];
    rep(i,10){
        dp[0][i] = -1;
    }
    for(int i=1; i<=n; i++){
        long double curlog = log10(a[i]);
        rep(j,10) dp[i][j] = dp[i-1][j];
        rep(j,10) bt[i][j] = -1;
        rep(j,10){
            if(dp[i-1][j] == -1) continue;
            ll last = (a[i]*j)%10;
            if(dp[i][last] < dp[i-1][j] + curlog){
                dp[i][last] = dp[i-1][j] + curlog;
                bt[i][last] = j;
            }
        }
        if(dp[i][a[i]%10] < curlog){
            dp[i][a[i]%10] = curlog;
            bt[i][a[i]%10] = -2; //represents a new starting
        }

    }   

    if(dp[n][d] < 0){
        cout<<-1<<endl;
        exit(0);
    }
    //backtracking
    vi ans; //stores the indices of the answers.
    ll prev=d;
    repD(i,n,1){
        if(bt[i][prev] == -1) continue;

        ans.pb(i);
        if(bt[i][prev] == -2) break;
        prev = bt[i][prev];
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<a[x]<<" ";
    }
    timer();
    return 0;
}