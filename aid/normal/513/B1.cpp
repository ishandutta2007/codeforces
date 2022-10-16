#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10, F = 1000 * 1000 + 5;
int p[MAXN], q[F][MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        p[i] = i;
    int cnt = 0, fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    int ans = 0;
    for(int per = 0; per < fact; per++) {
        int cur = 0;
        for(int i = 0; i < n; i++) {
            int segMin = p[i];
            for(int j = i + 1; j < n; j++) {
                cur += segMin;
                segMin = min(segMin, p[j]);
            }
            cur += segMin;
        }
        ans = max(ans, cur);
        next_permutation(p, p + n);
    }
    for(int i = 0; i < n; i++)
        p[i] = i;
    for(int per = 0; per < fact; per++) {
        int cur = 0;
        for(int i = 0; i < n; i++) {
            int segMin = p[i];
            for(int j = i + 1; j < n; j++) {
                cur += segMin;
                segMin = min(segMin, p[j]);
            }
            cur += segMin;
        }
        if(ans == cur) {
            for(int i = 0; i < n; i++)
                q[cnt][i] = p[i];
            cnt++;
        }
        next_permutation(p, p + n);
    }
    for(int i = 0; i < n; i++)
        cout << q[m - 1][i] + 1 << ' ';
    cout << '\n';
    return 0;
}