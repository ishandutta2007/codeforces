#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
const int MAXK = 20 + 2;

int a[MAXN][MAXK], cnt_set[MAXN];
int pw[MAXK];
map<int,int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    pw[0] = 1;
    for (int i = 1; i < 20; i++)
        pw[i] = pw[i - 1] * 3;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int my_id = 0;
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            my_id += a[i][j] * pw[j];
        }
        mp[my_id] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int other = 0;
            for (int x = 0; x < k; x++) {
                if (a[i][x] == a[j][x])
                    other += a[i][x] * pw[x];
                else
                    other += (3 - a[i][x] - a[j][x]) * pw[x];
            }
            if (mp.count(other) and mp[other] > j) {
                cnt_set[i]++;
                cnt_set[j]++;
                cnt_set[mp[other]]++;
            }
        }
    }
    long long answer = 0;
    for (int i = 0; i < n; i++)
        if (cnt_set[i] > 1)
            answer += cnt_set[i] * (cnt_set[i] - 1) / 2;
    cout << answer << '\n';
}