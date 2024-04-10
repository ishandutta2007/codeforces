#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long lint;

int ka[26];
int kb[26];
int kc[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    for (auto i : a) {
        ka[i - 'a']++;
    }
    for (auto i : b) {
        kb[i - 'a']++;
    }
    for (auto i : c) {
        kc[i - 'a']++;
    }
    int ans = 0;
    int ai = -1;
    int am = -1;
    for (int i = 0; i <= 1e5; ++i) {
        bool ok = true;
        for (int j = 0; j < 26; ++j) {
            if (ka[j] < 1LL * kb[j] * i) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            break;
        }
        int m = 1e9;
        for (int j = 0; j < 26; ++j) {
            if (kc[j] == 0) {
                continue;
            }
            m = min(m, (ka[j] - i * kb[j]) / kc[j]);
        }
        if (m + i > ans) {
            ans = m + i;
            ai = i;
            am = m;
        }
    }
    for (int i = 0; i < ai; ++i) {
        cout << b;
        for (auto j : b) {
            ka[j - 'a']--;
        }
    }
    for (int i = 0; i < am; ++i) {
        cout << c;
        for (auto j : c) {
            ka[j - 'a']--;
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < ka[i]; ++j) {
            cout << (char) (i + 'a');
        }
    }

    return 0;
}