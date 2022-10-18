#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[1005][2];
int used[1005][1005];
map < pair < int, int >, int > cnt;

int gcd(int a, int b){
    a = abs(a), b = abs(b);
    while (a > 0 && b > 0){
        int t = a % b;
        a = b;
        b = t;
    }
    return a + b;
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, add = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1];
    vector < pair < int, int > > Q;
    for (int i = 1; i <= n; ++i){
        for (int j = 2; j <= n; ++j){
            if (used[i][j] == 1) continue;
            vector < int > pos = {i, j};
            int A = a[i][1] - a[j][1], B = a[j][0] - a[i][0], C = a[i][0] * a[j][1] - a[i][1] * a[j][0];
            for (int z = j + 1; z <= n; ++z){
                if (a[z][0] * A + B * a[z][1] + C == 0) pos.push_back(z);
            }
            for (auto key : pos){
                for (auto key1 : pos){
                    used[key][key1] = 1;
                }
            }
            int k = gcd(A, B);
            if (A / k < 0) k *= (-1);
            else if (A / k == 0){
                if (B / k <= 0) k *= (-1);
            }
            cnt[{A / k, B / k}]++;
            add++;
        }
    }
    for (auto key : cnt){
        ans += key.second * (add - key.second);
    }
    cout << ans / 2 << '\n';
    return 0;
}