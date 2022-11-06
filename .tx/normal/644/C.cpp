#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

using namespace std;

map < string, vector <string> > mp;
map < vector <string>, vector <string> > pm;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int len = s.length();
        int cnt = 0, pos = len;
        for (int j = 0; j < len; j++) {
            if (s[j] == '/') {
                cnt++;
                if (cnt == 3) {
                    pos = j;
                    break;
                }
            }
        }
        string host = s.substr(0, pos);
        string path = s.substr(pos);
        mp[host].push_back(path);
    }
    //oo
    for (auto p : mp) {
        vector <string> &z = p.second;
        sort(z.begin(), z.end());
        z.resize(unique(z.begin(), z.end()) - z.begin());
        pm[z].push_back(p.first);
    }
    int sz = 0;
    for (auto p : pm) {
        vector <string> &z = p.second;
        if (z.size() < 2) {
            continue;
        }
        sz++;
    }
    printf("%d\n", sz);
    for (auto p : pm) {
        vector <string> &z = p.second;
        if (z.size() < 2) {
            continue;
        }
        for (int j = 0; j < (int) z.size(); j++) {
            if (j > 0) {
                putchar(' ');
            }
            printf("%s", z[j].c_str());
        }
        printf("\n");
    }
    return 0;
}