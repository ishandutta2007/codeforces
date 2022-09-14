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

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    set<int> s;
    int ans = 0;
    vector<int> ansl, ansr;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(a[i]) != s.end()) {
            s.clear();
            ans++;
            ansl.push_back(l + 1);
            ansr.push_back(i + 1);
            l = i + 1;
        }
        else
            s.insert(a[i]);
    }
    if (!ansr.empty())
        ansr[(int)ansr.size() - 1] = n;
    if (ans == 0 && !s.empty()) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
        cout << ansl[i] << " " << ansr[i] << endl;
}