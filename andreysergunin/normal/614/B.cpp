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
    string ans;
    int z = 0;
    bool t = true;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bool f = true;
        if (s[0] != '1')
            f = false;
        for (int i = 1; i < s.size(); i++)
            if (s[i] != '0')
                f = false;
        if (s == "0")
            t = false;
        if (!f)
            ans = s;
        else
            z += (int)s.size() - 1;
    }
    if (!t) {
        cout << 0;
        return 0;
    }
    if (ans.size() == 0)
        ans = "1";
    for (int i = 0; i < z; i++)
       ans += '0';
    cout << ans;
    return 0;
}