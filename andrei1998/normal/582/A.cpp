#include <iostream>
#include <set>

using namespace std;

int gcd (int a, int b) {
    int r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

const int NMAX = 505;
int v[NMAX * NMAX];

multiset <int> Set;
int ans[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for (int i = 1; i <= n * n; ++ i) {
        cin >> v[i];
        Set.insert(-v[i]);
    }

    int j;
    for (int i = 1; i <= n; ++ i) {
        ans[i] = -*Set.begin();

        for(j = 1; j <= i; ++ j) {
            Set.erase(Set.find(-gcd(ans[i], ans[j])));

            if (i != j)
                Set.erase(Set.find(-gcd(ans[i], ans[j])));
        }
    }

    for (int i = 1; i <= n; ++ i)
        cout << ans[i] << " \n"[i == n];
    return 0;
}