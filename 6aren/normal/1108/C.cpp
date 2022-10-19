#include <bits/stdc++.h>

using namespace std;

int n;

string s;

int main() {
    cin >> n >> s;
    //rgb= 012 021 102
    int mini = 1e6, mmrr, mmrg, mmrb;
    for (int r = 0; r < 3; r++) {
        for (int g = 0; g < 3; g++) {
            for (int b = 0; b < 3; b++) {
                if ((r + 1) * (g + 1) * (b + 1) != 6) {
                    continue;
                }
                int cnt = 0;
                for (int i = 0; i < s.size(); i++) {
                    if ((s[i] == 'R') && (i % 3 != r)) cnt++;
                    if ((s[i] == 'G') && (i % 3 != g)) cnt++;
                    if ((s[i] == 'B') && (i % 3 != b)) cnt++;
                }
                if (cnt < mini) {
                    mini = cnt;
                    mmrr = r;
                    mmrg = g;
                    mmrb = b;
                }
            }
        }
    }
    cout << mini << endl;
    for (int i = 0; i < s.size(); i++) {
        if (i % 3 == mmrr) cout << 'R';
        if (i % 3 == mmrg) cout << 'G';
        if (i % 3 == mmrb) cout << 'B';
    }
    cin >> n;
    return 0;
}