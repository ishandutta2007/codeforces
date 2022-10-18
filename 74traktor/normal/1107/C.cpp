#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[200005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i - 1];
    string s;
    cin >> s;
    multiset < int > G;
    int ans = 0;
    G.insert(a[0]);
    ans = a[0];
    for (int i = 1; i < n; ++i){
        if (s[i] == s[i - 1]){
            if ((int)G.size() == k){
                int p = (*G.begin());
                if (a[i] > p){
                    ans += (a[i] - p);
                    G.erase(G.begin());
                    G.insert(a[i]);
                }
            }
            else{
                G.insert(a[i]);
                ans += a[i];
            }
        }
        else{
            ans += a[i];
            G = {a[i]};
        }
    }
    cout << ans << endl;
    return 0;
}