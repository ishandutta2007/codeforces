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
#define inf (int)1e9
#define eps 1e-9
#define pi acos(-1)
#define mod 1000000007

string num, dum; int n, j, Z, cnt = 0, flag = 1, ff = 1;

int Zero (string X) {
    int i, L = X.length();
    if (L == 1) return X == "1" ? 0 : -1;
    if (X[0] != '1') return -1;
    for (i = 1; i < L; i++) if (X[i] != '0') return -1;
    return L - 1;
}

int main () {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
        cin >> num; Z = Zero(num);
        if (num == "0") flag = 0;
        else if (Z == -1) dum = num, ff = 0;
        else cnt += Z;
    }
    if (ff) dum = "1";
    if (flag) {
        cout << dum;
        for (j = 0; j < cnt; j++) cout << "0";
    } else cout << 0;
    return 0;
}