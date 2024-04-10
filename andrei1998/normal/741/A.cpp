#include <bits/stdc++.h>

#define lint long long int
using namespace std;

lint gcd(lint a, lint b) {
    if (!b)
        return a;

    lint r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

lint lcm(lint a, lint b) {
    lint d = gcd(a, b);
    return a / d * b;
}

int n;
int perm[105];

int enter[105];

bool vis[105];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> perm[i];
        ++ enter[perm[i]];
    }

    for (int i = 1; i <= n; ++ i)
        if (enter[i] != 1) {
            cout << "-1\n";
            return 0;
        }

    lint ans = 1;
    for (int i = 1; i <= n; ++ i)
        if (!vis[i]) {
            int node = i;
            int l = 0;

            while (!vis[node]) {
                vis[node] = true;
                ++ l;
                node = perm[node];
            }

            if (l % 2 == 0)
                l /= 2;
            ans = lcm(ans, l);
        }


    cout << ans << '\n';
    return 0;
}