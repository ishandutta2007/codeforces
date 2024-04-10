#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int sum = 0;
        bool flag1 = 0;
        int32_t flag2 = 0;
        for (auto u : s) {
            sum += (u - '0');
            flag1 |= (u == '0'); 
            flag2 += ((u - '0') % 2 == 0);
        }
        if (sum % 3 == 0 && flag1 && flag2 >= 2) cout << "red\n";
        else cout << "cyan\n";
    }
    return 0;
}