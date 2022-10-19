#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 200005;

map<int, int> cnt;
__int128 ans;

std::string toString(__int128 num) {
    std::string str;
    bool sign = (num >= 0);
    if (num < 0) num = -num;
    do {
        int digit = num % 10;
        str = std::to_string(digit) + str;
        num = (num - digit) / 10;
    } while (num != 0);
    if (!sign) str = "-" + str;
    return str;
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    int mem = 0;
    for (int i = 1; i <= n; i++) {
        int foo;
        cin >> foo;
        int temp = sum;
        int cntt = 0;
        for (int j = -1; j <= 1; j++) {
            temp -= cnt[foo + j] * (foo + j);
            cntt += cnt[foo + j];
        }
        ans += (i - 1 - cntt) * foo - temp;
        sum += foo;
        cnt[foo]++;
    }
    cout << toString(ans);
    return 0;
}