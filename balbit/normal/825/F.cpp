#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i = n-1; i>=0; i--)
#define MX(a,b) a = max(a, (__typeof__(a))(b))
#define MN(a,b) a = min(a, (__typeof__(a))(b))
#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
 
using namespace std;
 
// #define int ll
 
const ll mod = 1e9+7;
 
 
 
 
ll inv (int b){
    if (b==1) return 1;
    return inv(mod%b) * (mod - mod/b) % mod;
}
 
const int maxn = 8005;
 
 
void GG(){
    cout<<-1<<endl; exit(0);
}
 
 int dp[maxn];
 int ndig[maxn];
 
signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    REP(i,n+1){
        ndig[i] = log10(i)+1;
    }
    RREP(i,n){
        int lf = n-i;
        vector<int> f(lf+1);
        f[0]=-1;
        FOR(j,1,n-i){
            f[j] = f[j-1];
            while (f[j]!=-1 && s[i+j] != s[i+f[j]+1]) {
                f[j] = f[f[j]];
            }
            if (s[i+j] == s[i+f[j]+1]) f[j]++;
        }
        dp[i] = 1e9;
        FOR(j,i,n){
            int ln = j-i+1-(f[j-i]+1);
            int nd = 1;
            if ((j-i+1) %ln==0){
                nd = (j-i+1)/ln;
            }else ln = j-i+1;
            MN(dp[i], dp[j+1] + ndig[nd] + ln );
        }
    }
    cout<<dp[0]<<endl;
}