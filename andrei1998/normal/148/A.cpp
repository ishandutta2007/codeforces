#include <iostream>
#include <algorithm>

using namespace std;

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

int v[4];

int main()
{
    int d;
    for (int i = 0; i < 4; ++ i)
        cin >> v[i];
    cin >> d;

    int ans = 0;
    for (int i = 0; i < (1 << 4); ++ i) {
        bool par = 0;

        int val = 1;
        for (int j = 0; j < 4; ++ j)
            if (i & (1 << j)) {
                par ^= 1;
                val = lcm(val, v[j]);
            }

        val = d / val;
        if (!par)
            ans += val;
        else
            ans -= val;
    }

    cout << d - ans << '\n';
    return 0;
}