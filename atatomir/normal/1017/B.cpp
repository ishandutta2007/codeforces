#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 100011;

int n, i, a1, b1, a2, b2;
char a[maxN], b[maxN];
int cnt[2][2];
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s\n%s", &n, a + 1, b + 1);
    for (i = 1; i <= n; i++)
        cnt[a[i] - '0'][b[i] - '0']++;

    for (a1 = 0; a1 < 2; a1++) {
        for (b1 = 0; b1 < 2; b1++) {
            for (a2 = 0; a2 < 2; a2++) {
                for (b2 = 0; b2 < 2; b2++) {
                    if ((a1 | b1) == (a2 | b1) &&
                        (a2 | b2) == (a1 | b2)) continue;

                    ans += 1LL * cnt[a1][b1] * cnt[a2][b2];
                }
            }
        }
    }

    cout << ans / 2;




    return 0;
}