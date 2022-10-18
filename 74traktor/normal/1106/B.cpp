#include <bits/stdc++.h>

using namespace std;

#define int long long
unordered_map < int, int > kol;
set < pair < int, int > > Q;

int a[100005];
int c[100005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        kol[i] = a[i];
    }
    for (int i = 1; i <= n; ++i){
        cin >> c[i];
        Q.insert({c[i], i});
    }
    for (int i = 1; i <=  m; ++i){
        int x, what, cnt = 0;
        cin >> what >> x;
        int oct = kol[what];
        cnt += min(x, oct) * c[what];
        int x1 = x;
        x -= min(oct, x);
        oct -= min(oct, x1);
        kol[what] = oct;
        if (kol[what] == 0) Q.erase({c[what], what});
        while (x > 0 && (int)Q.size() != 0){
            auto p = (*Q.begin());
            int oct = kol[p.second];
            int x1 = x;
            cnt += min(oct, x) * c[p.second];
            x -= min(oct, x);
            oct -= min(oct, x1);
            kol[p.second] = oct;
            if (kol[p.second] == 0) Q.erase({c[p.second], p.second});
        }
        if (x != 0) cnt = 0;
        //for (int j = 1; j <= n; ++j) cout << kol[j] << " ";
        //cout << endl;
        cout << cnt << '\n';
    }
    return 0;
}