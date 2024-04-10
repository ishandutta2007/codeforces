#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
bool min(string x, string y){
    if (y == "-1")
        return 1;
    if (x.size() != y.size())
        return x.size() < y.size();
    for(int i = 0; i < x.size(); ++i)
        if (x[i] != y[i])
            return x[i] < y[i];
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string ans = "-1";
        for(int i = 0; i < 10; ++i){
            int c = n / 9;
            if (i + k < 10)
                c = 0;
            for(int j = 0; j <= c; ++j){
                if (i + k >= 10 && j == 0)
                    continue;
                int cursum = (i + (i + k)) * (k + 1) / 2;
                if (j != 0){
                    int b = 10 - i, a = k + 1 - b;
                    cursum = (i + 9) * b / 2 + b * 9 * (j - 1) + (1 + a) * a / 2;
                }
                cursum = n - cursum;
                if (cursum < 0 || cursum % (k + 1) != 0)
                    continue;
                cursum /= (k + 1);
                string s = "";
                s += char('0' + i);
                for(int z = 0; z < j - 1; ++z)
                    s += '9';
                int maxn = 9;
                if (i + k >= 10)
                    maxn = 8;
                while(cursum != 0){
                    int d = min(cursum, maxn);
                    maxn = 9;
                    cursum -= d;
                    s += char('0' + d);
                }
                reverse(s.begin(), s.end());
                if (min(s, ans))
                    ans = s;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}