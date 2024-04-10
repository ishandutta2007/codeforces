#include <bits/stdc++.h>
using namespace std;

#define int long long
//#define endl "\n"

typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a, b;
        int dd = 1;
        if (s[0] == '-') {
            dd = -1;
            s = s.substr(1, s.size() - 1);
        }
        a = 0;
        b = 0;
        int ind = 0;
        while (s[ind] != '.') {
            a *= 10;
            a += s[ind] - '0';
            ind++;
        }
        ind++;
        while (ind < s.size()) {
            b *= 10;
            b += s[ind] - '0';
            ind++;
        }
        a *= dd;
        b *= dd;
        arr[i] = {a, b};
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i].first;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i].second == 0)
            continue;
        if (sum > 0) {
            if (arr[i].second < 0) {
                arr[i].first--;
                sum--;
            }
        } else if (sum < 0){
            if (arr[i].second > 0) {
                arr[i].first++;
                sum++;
            }
        } else {
        
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << endl;
        ans += arr[i].first;
    }
    assert(ans == 0);
    return 0;
}