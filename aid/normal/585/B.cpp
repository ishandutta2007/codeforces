#include <iostream>
#include <map>

using namespace std;

const int MAXN = 105, MAXM = 30;
int dp[MAXN][3], l[MAXM], r[MAXM], row[MAXM];
char c[3][MAXN], cc[MAXM];
map<char, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++) {
        int n, k;
        cin >> n >> k;
        int sp = 0, id = 0;
        mp.clear();
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < n; j++) {
                cin >> c[i][j];
                if('A' <= c[i][j] && c[i][j] <= 'Z' &&
                   mp.find(c[i][j]) == mp.end()) {
                    mp[c[i][j]] = id;
                    cc[id] = c[i][j];
                    id++;
                }
            }
        for(int i = 0; i < 3; i++)
            if(c[i][0] == 's')
                sp = i;
        for(int i = 0; i < k; i++) {
            bool found = false;
            for(int j = 0; j < 3 && !found; j++)
                for(int ll = 0; ll < n && !found; ll++)
                    if(c[j][ll] == cc[i]) {
                        row[i] = j;
                        l[i] = ll;
                        r[i] = ll + 1;
                        while(r[i] < n && c[j][r[i]] == c[j][ll])
                            r[i]++;
                        found = true;
                    }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 3; j++)
                dp[i][j] = 0;
        dp[0][sp] = 1;
        for(int i = 0; i < n - 1; i++)
            for(int j = 0; j < 3; j++)
                if(dp[i][j]) {
                    for(int d = -1; d <= 1; d++) {
                        int x = i + 1, y = j;
                        bool bad = false;
                        for(int tr = 0; tr < k; tr++)
                            if(row[tr] == y && l[tr] - 2 * i <= x && x < r[tr] - 2 * i)
                                bad = true;
                        y = j + d;
                        if(y < 0 || y >= 3)
                            continue;
                        for(int tr = 0; tr < k; tr++)
                            if(row[tr] == y && l[tr] - 2 * i <= x && x < r[tr] - 2 * i)
                                bad = true;
                        for(int tr = 0; tr < k; tr++)
                            if(row[tr] == y && l[tr] - 2 * i - 1 <= x && x < r[tr] - 2 * i - 1)
                                bad = true;
                        for(int tr = 0; tr < k; tr++)
                            if(row[tr] == y && l[tr] - 2 * i - 2 <= x && x < r[tr] - 2 * i - 2)
                                bad = true;
                        if(!bad)
                            dp[x][y] = 1;
                    }
                }
        bool ok = false;
        for(int i = 0; i < 3; i++)
            if(dp[n - 1][i])
                ok = true;
        cout << (ok? "YES" : "NO") << '\n';
    }
    return 0;
}