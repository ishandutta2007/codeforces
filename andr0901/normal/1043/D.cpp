#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> v(m, vector <int> (n));
    vector <int> templ(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        templ[t - 1] = i;
        v[0][i] = i;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            t--;
            v[i][templ[t]] = j;
        }
    }
    /*for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }*/
    long long ans = 1;
    int cur = 1;
    for (int i = 1; i < n; i++) {
        bool flag = 1;
        for (int j = 0; j < m; j++) {
            if (v[j][i] - v[j][i - 1] != 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            //cout << i << " ";
            cur++;
        } else {
            cur = 1;
        }
        ans += cur;
    }
    cout << ans;
    return 0;
}