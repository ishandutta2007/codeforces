#include <bits/stdc++.h>

using namespace std;

#define int long long
int out[55];
int st[55];
int d[55];
int maxn = 1e18;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, a, b, m;
    cin >> q;
    bool flag;
    st[0] = 1;
    st[1] = 1;
    for (int i = 2; i <= 50; ++i) st[i] = st[i - 1] * 2;
    for (int i = 1; i <= q; ++i){
        cin >> a >> b >> m;
        flag = true;
        if (a == b){
            cout << 1 << " " << a << '\n';
            continue;
        }
        out[1] = a;
        for (int len = 2; len <= 50; ++len){
            int sum1 = a;
            for (int j = 2; j <= len; ++j){
                out[j] = (sum1 + 1);
                sum1 += out[j];
            }
            if (out[len] > b) break;
            sum1 = out[len];
            for (int j = 2; j <= len; ++j){
                int l = 1, r = m + 1;
                while (r - l > 1){
                    int mid = (r + l) / 2;
                    if ((double)st[len - j] - maxn / (double)mid >= 0.0){
                        r = mid;
                        continue;
                    }
                    if (mid * st[len - j] - st[len - j] <= b - sum1){
                        l = mid;
                    }
                    else r = mid;
                }
                sum1 += l * st[len - j];
                d[j] = l;
                sum1 -= st[len - j];
            }
            if (sum1 == b){
                flag = false;
                out[1] = a;
                int sum = a;
                for (int j = 2; j <= len; ++j){
                    out[j] = sum + d[j];
                    sum += out[j];
                }
                cout << len << " ";
                for (int j = 1; j <= len; ++j) cout << out[j] << " ";
                cout << '\n';
                break;
            }
        }
        if (flag) cout << -1 << '\n';
    }
    return 0;
}