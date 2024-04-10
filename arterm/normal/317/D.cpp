#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

#define M 100100

int g[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

bool u[M];

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout); 
#endif
    ios_base::sync_with_stdio(0);

    int n, fee = 0, ans = 0;
    cin >> n;
    for (int i = 2; i <= n && i < M; ++i)
        if (!u[i]) {
            int len = 0;
            long long x = i;
            while (x <= n) {
                ++len;
                x *= i;
                if (x >= M && x <= n)
                    ++fee;
                else if (x < M)
                    u[x] = true;
            }
            ans ^= g[len];
        }

    if ((1 + max(0, n - M + 1 - fee)) % 2)
        ans ^= 1;

    if (ans)
        cout << "Vasya\n";
    else
        cout << "Petya\n";

    return 0;
}