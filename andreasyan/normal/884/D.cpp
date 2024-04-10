#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
multiset<long long> s;

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    long long ans = 0;
    if (n % 2 == 0)
        s.insert(0);
    while (s.size() > 1)
    {
        if (s.size() >= 3)
        {
            long long x = 0;
            x += *s.begin();
            s.erase(s.begin());
            x += *s.begin();
            s.erase(s.begin());
            x += *s.begin();
            s.erase(s.begin());
            ans += x;
            s.insert(x);
        }
        else
        {
            long long x = 0;
            x += *s.begin();
            s.erase(s.begin());
            x += *s.begin();
            s.erase(s.begin());
            ans += x;
            s.insert(x);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}