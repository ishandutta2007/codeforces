#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

ll d, k;

bool solv()
{
    scanf("%lld%lld", &d, &k);
    ll z;
    for (z = 0; 2 * z * z <= d * d; z += k){}
    z -= k;
    if ((z + k) * (z + k) + z * z > d * d)
        return false;
    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("Ashish\n");
        else
            printf("Utkarsh\n");
    }
    return 0;
}