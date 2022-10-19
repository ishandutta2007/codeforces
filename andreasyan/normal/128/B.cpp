#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n;
long long k;
char a[N];

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    scanf("%lld", &k);
    if (k > n * 1LL * (n + 1) / 2)
    {
        printf("No such line.\n");
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i);
    }
    for (int i = 0; i < n; ++i)
    {
        if (k <= 0)
        {
            putchar('\n');
            return 0;
        }
        long long s[26] = {};
        int q[26] = {};
        for (int j = 0; j < v.size(); ++j)
        {
            s[a[v[j]] - 'a'] += (n - v[j]);
            q[a[v[j]] - 'a']++;
        }
        for (int j = 0; j < 26; ++j)
        {
            if (k <= s[j])
            {
                putchar(j + 'a');
                k -= q[j];
                vector<int> vv;
                for (int k = 0; k < v.size(); ++k)
                {
                    if (a[v[k]] == j + 'a')
                    {
                        if (v[k] + 1 < n)
                            vv.push_back(v[k] + 1);
                    }
                }
                v = vv;
                break;
            }
            k -= s[j];
        }
    }
    return 0;
}