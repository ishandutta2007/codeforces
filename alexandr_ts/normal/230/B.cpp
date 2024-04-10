#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 10000001ll;
const ll MOD = 1000000007ll;

bool prime[N];

set <ll> divs;
set <ll> :: iterator it;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    ll tmp;
    for (int i = 0; i < n; ++i)
    {
        scanf("%I64d", &tmp);
        if (tmp == 1 || ((ll)sqrt(tmp)) * (ll)sqrt(tmp) != tmp)
        {
            printf("NO\n");
            continue;
        }
        ll sq = sqrt(tmp);
        bool fnd = true;
        for (int i = 2; i <= sqrt(sq); ++i)
            if (!(sq % i))
            {
                printf("NO\n");
                fnd = false;
                break;
            }
        if (fnd)
            printf("YES\n");

    }



}