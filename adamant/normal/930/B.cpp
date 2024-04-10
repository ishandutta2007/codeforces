#include <bits/stdc++.h>

using namespace std;


#define int int64_t
#define double long double

const int maxn = 5000, sigma = 26;

int uni[sigma][maxn][sigma];
int cnt[sigma];
double total[sigma][maxn];
double maxi[sigma];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        int a = s[i] - 'a';
        cnt[a];
        for(int j = 1; j < n; j++) {
            int b = s[(i + j) % n] - 'a';
            uni[a][j][b]++;
        }
    }
    for(int c = 0; c < sigma; c++) {
        for(int i = 0; i < n; i++) {
            double d = accumulate(uni[c][i], uni[c][i] + sigma, 0.);
            if(d) {
                total[c][i] = count(uni[c][i], uni[c][i] + sigma, 1) / d;
            } else {
                total[c][i] = 0;
            }
        }
        maxi[c] = *max_element(total[c], total[c] + n);
    }
    double ans = 0;
    for(int i = 0; i < n; i++) {
        ans += 1. * maxi[s[i] - 'a'] / n;
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
    return 0;
}