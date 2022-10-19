#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;

vector<long long> u[60];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        long long x;
        scanf("%I64d", &x);
        for (int j = 59; j >= 0; --j)
        {
            if ((x & (1LL << j)))
            {
                u[j].push_back(x);
                break;
            }
        }
    }
    vector<long long> v;
    for (int i = 59; i >= 0; --i)
    {
        if (u[i].empty())
            continue;
        int q = 0;
        for (int j = 0; j < v.size(); ++j)
        {
            if ((v[j] & (1LL << i)))
                ++q;
        }
        if (q + 1 < u[i].size())
        {
            printf("No\n");
            return 0;
        }
        vector<long long> vv;
        int k = 0;
        for (int j = 0; j < u[i].size(); ++j)
        {
            vv.push_back(u[i][j]);
            if (j != u[i].size() - 1)
            {
                while (k < v.size() && (v[k] & (1LL << i)) == 0)
                    vv.push_back(v[k++]);
                vv.push_back(v[k++]);
            }
        }
        while (k < v.size())
            vv.push_back(v[k++]);
        v = vv;
    }
    printf("Yes\n");
    for (int i = 0; i < n; ++i)
        printf("%I64d ", v[i]);
    printf("\n");
    return 0;
}