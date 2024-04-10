#include <iostream>
#include <cstdio>

using namespace std;
const long long p = 1e9 + 7;

struct SS{
    string s;
};
SS s[100];
bool use[100][30];


int main()
{
    long long n, m, i, j, ans = 1, k;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> s[i].s;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            use[j][(int)s[i].s[j] - 'A'] = true;
    for (i = 0; i < m; i++){
        k = 0;
        for (j = 0; j < 26; j++)
            k += use[i][j];
        ans = (ans * k) % p;
    }
    cout << ans;

    return 0;
}