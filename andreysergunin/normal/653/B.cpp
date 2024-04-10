#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;


vector<string> a;
vector<char> b;
int ans = 0;
int n, q;
vector<int> cur;

void enumerate(int k) {
    if (k == n) {
        vector<int> s(cur);
        for (int i = 0; i < n - 1; i++) {
            bool f = false;
            for (int j = 0; j < q; j++) {
                if (a[j][0] - 'a' == s[i] && a[j][1] - 'a' == s[i + 1]) {
                    s[i + 1] = b[j] - 'a';
                    f = true;
                    break;
                }
            }
            if (!f)
                return;
        }
        if (s[n - 1] == 0)
            ++ans;
        return;
    }
    for (int i = 0; i < 6; i++) {
        cur[k] = i;
        enumerate(k + 1);
    }
}

int main() {
    cin >> n >> q;
    a.resize(q);
    b.resize(q);
    cur.resize(n);
    for (int i = 0; i < q; i++)
        cin >> a[i] >> b[i];
    enumerate(0);
    cout << ans << endl;
    return 0;
}