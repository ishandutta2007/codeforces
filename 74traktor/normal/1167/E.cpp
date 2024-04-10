#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[1000005];
int last[1000005];
int f[1000005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        last[a[i]] = i;
        if (f[a[i]] == 0) f[a[i]] = i;
    }
    int ans = 0, r;
    set < pair < int, int > > Q;
    int R = n + 1, L = -1;
    for (int i = 0; i <= x - 1; ++i){
        int l = i + 1;
        if (i == 0){
            r = x - 1;
            if (last[r + 1] != 0) R = f[r + 1];
            while (r >= l){
                if (f[r + 1] != 0) Q.insert({f[r + 1], r + 1});
                if (last[r] < R){
                    if (last[r] != 0) R = f[r];
                    r--;
                }
                else break;
            }
            r = max(r, l);
            ans += (x - r + 1);
        }
        else{
            if (last[i] == 0 || f[i] > L){
                L = max(L, last[i]);
                if (last[i] == 0){
                    r = max(r, l);
                    ans += (x - r + 1);
                }
                else{
                    auto it = Q.lower_bound({last[i], -1});
                    pair < int, int > ch;
                    if (it == Q.end()) ch = {-1, -1};
                    else ch = (*it);
                    while ((int)Q.size() > 0 && (*Q.begin()) != ch){
                        r = max(r, (*Q.begin()).second);
                        Q.erase((*Q.begin()));
                    }
                    r = max(r, l);
                    ans += (x - r + 1);
                }
            }
            else{
                break;
            }
        }
        //cout << i << " " << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}