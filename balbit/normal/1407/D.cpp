
#include <bits/stdc++.h>
using namespace std;

#define ll long long

#ifdef BALBITe
#define bug(...) cerr<<"#"<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S&&...y){cerr<<x<<", "; _do(y...);}
#define IOS()

#else
#define IOS() ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define bug(...)
#endif


#define pb push_back

const int maxn = 3e5+5;
int dp[maxn];
int h[maxn];

signed main(){
    IOS();
    memset(dp, 0x3f, sizeof dp);
    int n; cin>>n;
    vector<int> a1, a2;
    dp[1] = 0;

    for(int i = 1; i<=n; ++i) {
        cin>>h[i];
        while(!a1.empty() && h[i] > h[a1.back()]) {
            dp[i] = min(dp[i], dp[a1.back()]);
            a1.pop_back();
        }
        if(!a1.empty()) dp[i] = min(dp[i], dp[a1.back()]);
        while(!a1.empty() && h[i] == h[a1.back()]) a1.pop_back();
        a1.pb(i);

        //
        while(!a2.empty() && h[i] < h[a2.back()]) {
            dp[i] = min(dp[i], dp[a2.back()]);
            a2.pop_back();
        }
        if(!a2.empty()) dp[i] = min(dp[i], dp[a2.back()]);
        while(!a2.empty() && h[i] == h[a2.back()]) a2.pop_back();
        a2.pb(i);
        ++dp[i];
    }

    cout<<dp[n]-1<<endl;
}