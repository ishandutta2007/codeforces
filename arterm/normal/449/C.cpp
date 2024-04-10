#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <queue>

using namespace std;

#define M 100100

int n, s[M];
bool u[M], prime[M];
vector<pair<int, int>> ans;


void sito() {
    fill(s, s + M, M);
    for (int i = 2; i <= n; ++i)
        if (!u[i]) {
            prime[i] = true;
            for (int j = i; j <= n; j += i) {
                u[j] = true;
                s[j] = min(s[j], i);
            }
        }
}

void kill() {
    vector<int> to;
    fill(u, u + M, false);
    for (int i = n; i > 1; --i)
        if (prime[i]) {
            int p = i;

            for (int j = p; j <= n; j += p)
                if (s[j] == p && !u[j]) {
                    to.push_back(j);
                    u[j] = true;
                }

            if (to.size() % 2 == 1) {
                for (int j = p; j <= n; j += p)
                    if (!u[j]) {
                        to.push_back(j);
                        u[j] = true;
                        break;
                    }
            }

            for (int i = 0; i + 1 < (int) to.size(); i += 2)
                ans.push_back(make_pair(to[i], to[i + 1]));

            to.clear();
        }

    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x.first << " " << x.second << "\n";
}


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    cin >> n;
    sito();
    kill();

    return 0;
}