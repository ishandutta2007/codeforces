/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;

#define checkbit(n, b) ((n >> b) & 1)
#define gcd __gcd
#define bitcount __bultin_popcount
#define inf (int)2e9
#define eps 1e-9
#define pi acos(-1)
#define mod 1000000007

int main () {
    int n; string a, b; cin >> n >> a >> b;
    if (b == "week") {
        if (n == 5 || n == 6) cout << "53\n";
        else cout << "52\n";
    } else {
        if (n <= 29) cout << "12\n";
        else if (n == 30) cout << "11\n";
        else cout << "7\n";
    }
    return 0;
}