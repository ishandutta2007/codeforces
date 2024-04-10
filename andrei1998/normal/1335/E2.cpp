#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200000 + 5;
const int VALMAX = 200 + 5;

vector<int> freq[VALMAX];
int s_part[VALMAX][NMAX];

void test() {
    for (int i = 1; i < VALMAX; ++i) {
        freq[i].clear();
    }
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int vl;
        cin >> vl;
        freq[vl].push_back(i);
        for (int j = 1; j < VALMAX; ++j) {
            s_part[j][i] = s_part[j][i - 1];
        }
        ++s_part[vl][i];
    }
    int ans = 0;
    for (int a = 1; a < VALMAX; ++a) {
        ans = max(ans, static_cast<int>(freq[a].size()));
        for (int b = 1; b < VALMAX; ++b) {
            if (a != b) {
                for (int i = 1; i - 1 < static_cast<int>(freq[a].size()) - i; ++i) {
                    ans = max(ans, 2 * i + s_part[b][freq[a][freq[a].size() - i]] - s_part[b][freq[a][i - 1] - 1]);
                }
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0;
    cin >> t;
    while (t--) {
        test();
    }
    return 0;
}