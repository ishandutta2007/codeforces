#include <bits/stdc++.h>

using namespace std;

#define int long long
map < int, int > pos;
double MAXN = 1e18;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, b;
    cin >> n >> b;
    int ans = 1e18;
    int i = 2;
    while (i * i <= b){
        if (b % i == 0){
            pos[i]++;
            b /= i;
            i -= 1;
        }
        ++i;
    }
    if (b != 1) pos[b]++;
    for (auto key : pos){
        int x = key.first, y = 0;
        while (x <= n){
            y += n / x;
            if ((double)x - MAXN / (double)key.first > 0.0001) break;
            x *= key.first;
        }
        ans = min(ans, y / key.second);
    }
    cout << ans << '\n';
    return 0;
}