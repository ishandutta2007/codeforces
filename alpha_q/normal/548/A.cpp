#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

main()
{
    string s, res; int k, siz, cnt = 0, ans = 0;
    cin >> s >> k;
    if (s.length() % k != 0) cout << "NO" << endl;
    else {
        siz = s.length()/k;
        res = "NO";
        for (int i = 0; i < k; i++) {
            int flag = 0;
            string str = "";
            for (int j = cnt; j < cnt + siz; j++) str += s[j];
            for (int k = 0; k < siz/2; k++) {
                if (str[k] != str[siz - k - 1]) {
                    flag++;
                    break;
                }
            }
            cnt += siz;
            if (flag != 0) break;
            else ans++;
        }
        if (ans == k) res = "YES";
        cout << res << endl;
    }
}