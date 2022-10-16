#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200000 + 5;
const int VALMAX = 200 + 5;

vector<int> freq[VALMAX];

int solve_ab(const string &s) {
    const int N = s.size() - 1;
    vector <int> s_part_b(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        s_part_b[i] = s_part_b[i - 1] + (s[i] == 'b');
    }

    int st = 1, dr = N, ans = 0;
    for (int cnt_a = 1; cnt_a <= N; ++cnt_a) {
        while (s[st] != 'a' && st <= dr) {
            ++st;
        }
        while (s[dr] != 'a' && st <= dr) {
            --dr;
        }
        ++st;
        --dr;
        if (st <= dr) {
            ans = max(ans, 2 * cnt_a + s_part_b[dr] - s_part_b[st - 1]);
        }
    }
    return ans;
}

void test() {
    for (int i = 1; i <= 200; ++i) {
        freq[i].clear();
    }
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int vl;
        cin >> vl;
        freq[vl].push_back(i);
    }
    int ans = 0;
    for (int a = 1; a <= 26; ++a) {
        ans = max(ans, static_cast<int>(freq[a].size()));
        for (int b = 1; b <= 26; ++b) {
            if (a != b) {
                int i = 0, j = 0;
                string str = "?";
                while (i < freq[a].size() || j < freq[b].size()) {
                    if (i < freq[a].size() && ((j == freq[b].size()) || freq[a][i] < freq[b][j])) {
                        ++i;
                        str += 'a';
                    } else {
                        ++j;
                        str += 'b';
                    }
                }
                ans = max(ans, solve_ab(str));
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