#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3003;

int n, k;
char a[N];

vector<vector<int> > vv;

int main()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", (a + 1));
    while (1)
    {
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == 'R' && a[i + 1] == 'L')
            {
                v.push_back(i);
            }
        }
        if (v.empty())
            break;
        for (int i = 0; i < v.size(); ++i)
        {
            swap(a[v[i]], a[v[i] + 1]);
        }
        vv.push_back(v);
    }
    if (k < vv.size())
    {
        printf("-1\n");
        return 0;
    }
    int maxu = 0;
    for (int i = 0; i < vv.size(); ++i)
    {
        maxu += vv[i].size();
    }
    if (k > maxu)
    {
        printf("-1\n");
        return 0;
    }
    int q = 0;
    for (int i = 0; i < vv.size(); ++i)
    {
        for (int j = 0; j < vv[i].size(); ++j)
        {
            ++q;
            if ((i + 1) + (maxu - q) == k)
            {
                for (int ii = 0; ii < i; ++ii)
                {
                    printf("%d ", vv[ii].size());
                    for (int jj = 0; jj < vv[ii].size(); ++jj)
                        printf("%d ", vv[ii][jj]);
                    printf("\n");
                }
                printf("%d ", (j + 1));
                for (int jj = 0; jj <= j; ++jj)
                    printf("%d ", vv[i][jj]);
                printf("\n");
                for (int jj = j + 1; jj < vv[i].size(); ++jj)
                {
                    printf("1 %d\n", vv[i][jj]);
                }
                for (int ii = i + 1; ii < vv.size(); ++ii)
                {
                    for (int jj = 0; jj < vv[ii].size(); ++jj)
                    {
                        printf("1 %d\n", vv[ii][jj]);
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}
/*
5 4
RRLLL
*/