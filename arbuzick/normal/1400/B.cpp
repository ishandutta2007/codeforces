#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int p, f;
        cin >> p >> f;
        int cnts, cntw;
        cin >> cnts >> cntw;
        int s, w;
        cin >> s >> w;
        int ans = 0;
        for(int i = 0; i <= cnts && i*s <= p; ++i){
            int ans1 = i;
            ans1 += min((p-s*i)/w, cntw);
            int s1 = cnts-i, w1 = cntw-min((p-s*i)/w, cntw);
            if(s < w){
                ans1 += min(f/s, s1);
                ans1 += min((f-min(f/s, s1)*s)/w, w1);
            }else{
                ans1 += min(f/w, w1);
                ans1 += min((f-min(f/w, w1)*w)/s, s1);
            }
            ans = max(ans, ans1);
        }
        cout << ans << '\n';
    }
    return 0;
}