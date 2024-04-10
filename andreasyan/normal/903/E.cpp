#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 5003;

int m, n;
char a[N][N];

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
        scanf(" %s", a[i]);
    for (int i = 0; i < m; ++i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            vector<int> v;
            for (int k = 0; k < n; ++k)
            {
                if (a[i][k] != a[j][k])
                {
                    v.push_back(k);
                }
            }
            if (!v.empty())
            {
                if (v.size() > 4)
                {
                    printf("-1\n");
                    return 0;
                }
                for (int k = 0; k < v.size(); ++k)
                {
                    for (int k1 = 0; k1 < n; ++k1)
                    {
                        if (v[k] == k1)
                            continue;
                        swap(a[i][v[k]], a[i][k1]);
                        bool z = true;
                        for (int j = 0; j < m; ++j)
                        {
                            if (i == j)
                                continue;
                            vector<int> v;
                            for (int k = 0; k < n; ++k)
                            {
                                if (a[i][k] != a[j][k])
                                {
                                    v.push_back(k);
                                }
                            }
                            if (v.empty())
                            {
                                bool u[26] = {};
                                for (int k = 0; k < n; ++k)
                                {
                                    u[a[j][k] - 'a'] = true;
                                }
                                int q = 0;
                                for (int k = 0; k < 26; ++k)
                                {
                                    if (u[k])
                                        ++q;
                                }
                                if (q == n)
                                {
                                    z = false;
                                    break;
                                }
                                continue;
                            }
                            if (v.size() != 2)
                            {
                                z = false;
                                break;
                            }
                            swap(a[j][v[0]], a[j][v[1]]);
                            bool zz = true;
                            for (int k = 0; k < v.size(); ++k)
                            {
                                if (a[i][v[k]] != a[j][v[k]])
                                {
                                    zz = false;
                                    break;
                                }
                            }
                            swap(a[j][v[0]], a[j][v[1]]);
                            if (!zz)
                            {
                                z = false;
                                break;
                            }
                        }
                        if (z)
                        {
                            printf("%s\n", a[i]);
                            return 0;
                        }
                        swap(a[i][v[k]], a[i][k1]);
                    }
                }
                swap(i, j);
                for (int k = 0; k < v.size(); ++k)
                {
                    for (int k1 = 0; k1 < n; ++k1)
                    {
                        if (v[k] == k1)
                            continue;
                        swap(a[i][v[k]], a[i][k1]);
                        bool z = true;
                        for (int j = 0; j < m; ++j)
                        {
                            if (i == j)
                                continue;
                            vector<int> v;
                            for (int k = 0; k < n; ++k)
                            {
                                if (a[i][k] != a[j][k])
                                {
                                    v.push_back(k);
                                }
                            }
                            if (v.empty())
                            {
                                bool u[26] = {};
                                for (int k = 0; k < n; ++k)
                                {
                                    u[a[j][k] - 'a'] = true;
                                }
                                int q = 0;
                                for (int k = 0; k < 26; ++k)
                                {
                                    if (u[k])
                                        ++q;
                                }
                                if (q == n)
                                {
                                    z = false;
                                    break;
                                }
                                continue;
                            }
                            if (v.size() != 2)
                            {
                                z = false;
                                break;
                            }
                            swap(a[j][v[0]], a[j][v[1]]);
                            bool zz = true;
                            for (int k = 0; k < v.size(); ++k)
                            {
                                if (a[i][v[k]] != a[j][v[k]])
                                {
                                    zz = false;
                                    break;
                                }
                            }
                            swap(a[j][v[0]], a[j][v[1]]);
                            if (!zz)
                            {
                                z = false;
                                break;
                            }
                        }
                        if (z)
                        {
                            printf("%s\n", a[i]);
                            return 0;
                        }
                        swap(a[i][v[k]], a[i][k1]);
                    }
                }
                printf("-1\n");
                return 0;
            }
        }
    }
    swap(a[0][0], a[0][1]);
    printf("%s\n", a[0]);
    return 0;
}