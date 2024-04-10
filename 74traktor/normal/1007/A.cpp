#include <bits/stdc++.h>

using namespace std;

map < int, int > d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, ans;
    cin >> n;
    ans = n;
    for (int i = 0; i < n; ++i){
        cin >> x;
        if (d.find(x) == d.end()) d[x] = 1;
        else d[x]++;
    }
    for (auto key : d) ans = min(ans, n - key.second);
    cout << ans << endl;
    return 0;
}