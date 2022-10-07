#include <iostream>
#include <algorithm>

using namespace std;
long long q[10];

int main()
{
    long long n;
    long long ans = 1e16;
    long long i, j, k, n1, res;
    cin >> n;
    for (i = 1; i * i <= n; i++){
        if (n % i != 0)
            continue;
        n1 = n / i;
        for (j = 1; j * j <= n1; j++){
            if (n1 % j != 0)
                continue;
            k = n1 / j;
            q[0] = i;
            q[1] = j;
            q[2] = k;
            sort(q, q + 3);
            res = (q[0] + 1) * (q[1] + 2) * (q[2] + 2);
            ans = min(res, ans);
        }
    }


    cout << ans - n << " " << 3 * 3 * (n + 1) - n;
    return 0;
}