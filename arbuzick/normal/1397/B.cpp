#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    int ans = 1000000000*n;
    for(int c = 1;; ++c){
        int st = 1, ans1 = 0;
        bool b = 0;
        for(int i = 0; i < n; ++i){
            if(st-a[i] > ans){
                b = 1;
                break;
            }
            ans1 += abs(st-a[i]);
            st *= c;
        }
        if(b)
            break;
        ans = min(ans, ans1);
    }
    cout << ans;
    return 0;
}