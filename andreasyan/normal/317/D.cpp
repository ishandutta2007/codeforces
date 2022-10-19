#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;
const int t[40] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

map<int, int> mp;
int rec(int s)
{
    if (mp.find(s) != mp.end())
        return mp[s];
    if (s == 0)
    {
        return mp[s] = 0;
    }
    set<int> u;
    for (int j = 1; j <= 30; ++j)
    {
        if ((s & (1 << j)))
        {
            int ss = s;
            for (int i = j; i <= 30; i += j)
            {
                if ((ss & (1 << i)))
                    ss ^= (1 << i);
            }
            u.insert(rec(ss));
        }
    }
    for (int i = 0; ; ++i)
    {
        if (u.find(i) == u.end())
            return mp[s] = i;
    }
}

void solv()
{
    /*int s = 0;
    for (int i = 1; i <= 30; ++i)
    {
        s |= (1 << i);
        cout << rec(s) << ", ";
    }*/
    int n;
    cin >> n;
    set<int> s;
    int ans = 0;
    for (int i = 1; i * i <= n; ++i)
    {
        if (s.find(i) != s.end())
            continue;
        if (i == 1)
        {
            s.insert(i);
            ans ^= t[1];
            continue;
        }
        int q = 0;
        long long j = i;
        while (j <= n)
        {
            s.insert(j);
            ++q;
            j *= i;
        }
        ans ^= t[q];
    }
    if ((n - s.size()) % 2 == 1)
        ans ^= t[1];
    if (ans)
        cout << "Vasya" << endl;
    else
        cout << "Petya" << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}