#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int ans;
multiset<int> s;
int x[3];
int q1, q2;

void han(int y)
{
    multiset<int>::iterator it = s.upper_bound(y);
    if (it != s.begin())
    {
        --it;
        if ((*it) <= x[0] + x[1])
            --q1;
        if ((*it) <= x[2])
            --q2;
        s.erase(it);
    }
}

void solv()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i)
        scanf("%d", &x[i]);
    sort(x, x + 3);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    if ((*(--s.end())) > x[0] + x[1] + x[2])
    {
        printf("-1\n");
        return;
    }
    while (1)
    {
        if (s.empty())
            break;
        if ((*(--s.end())) <= max(x[0] + x[1], x[2]))
            break;
        ++ans;
        if ((*(--s.end())) <= x[0] + x[2])
        {
            s.erase((--s.end()));
            han(x[1]);
            continue;
        }
        if ((*(--s.end())) <= x[1] + x[2])
        {
            s.erase((--s.end()));
            han(x[0]);
            continue;
        }
        s.erase((--s.end()));
    }
    q1 = q2 = 0;
    for (multiset<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        if ((*it) <= x[0] + x[1])
            ++q1;
        if ((*it) <= x[2])
            ++q2;
    }
    int yans = N;
    int ns = s.size() + 1;
    while (1)
    {
        if (s.size() == ns)
            break;
        yans = min(yans, ans + abs(q1 - q2) + max(0, (min(q1, q2) - abs(q1 - q2) + 1) / 2));
        ++ans;
        ns = s.size();
        han(x[0]);
        han(x[1]);
        han(x[2]);
    }
    if (s.empty())
        yans = min(yans, ans);
    printf("%d\n", yans);
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