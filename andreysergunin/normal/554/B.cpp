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

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    int cur = 1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])
            cur++;
        else
            cur = 1;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}