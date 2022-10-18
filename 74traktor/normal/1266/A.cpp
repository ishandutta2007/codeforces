#include<bits/stdc++.h>

using namespace std;

main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int ok1 = 0, sum = 0, cnt = 0;
        for (auto c : s) {
            if (c == '0') ok1 = 1;
            if ((c - '0') % 2 == 0) cnt++;
            sum += c - '0';
        }
        if (sum % 3 == 0 && ok1 && cnt > 1) cout << "red" << '\n';
        else cout << "cyan" << '\n';
    }
}