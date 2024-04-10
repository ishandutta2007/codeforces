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

ll t, ti, n, i;
vector<int> sm = {4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21};
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> t;
    for (ti = 1; ti <= t; ti++) {
        cin >> n;

        ans = -1;

        for (auto p : sm) {
            if (n < p) continue;

            for (auto s : sm) {
                if ( (n - p) % s == 0 )
                    ans = max(ans, 1LL + ( (n - p) / s ));
            }
        }

        if (n % 4 == 3 && n >= 15) {
            ans = max(ans, (n / 4) - 1);
        }

        cout << ans << '\n';
    }


    return 0;
}