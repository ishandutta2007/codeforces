#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    char mapp[300];
    mapp['R'] = 0;
    mapp['G'] = 5;
    mapp['B'] = 10;
    mapp['W'] = 15;
    mapp['Y'] = 20;
    mapp['5'] = 0;
    mapp['1'] = 1;
    mapp['2'] = 2;
    mapp['3'] = 3;
    mapp['4'] = 4;
    
    vector<int> cnt(25, 0);
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        ++cnt[mapp[str[0]] + mapp[str[1]]];
    }
    
    int ans = 10;
    vector<bool> vals(36, 0);
    for (int mask = 0; mask < 1024; ++mask) {
        vals.assign(36, 0);
        bool ok = 1;
        for (int i = 0; i < 5 && ok; ++i) {
            for (int j = 0; j < 5 && ok; ++j) {
                if (cnt[i * 5 + j]) {
                    int mark = 0;
                    mark += ((mask >> i) & 1) ? i : 5;
                    mark += (((mask >> (j + 5)) & 1) ? j : 5) * 6;
                    if (vals[mark]) ok = 0;
                    vals[mark] = 1;
                }
            }
        }
        if (ok) ans = min(ans, __builtin_popcount(mask));
    }
    cout << ans << endl;
}