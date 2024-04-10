#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

int mem[1000010];
int cnt[1000010][9];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int i, j;

    for(i = 1; i <= 1000000; i++)
    {
        if(i < 10)
            mem[i] = i;
        else
        {
            int t = i;
            while(!mem[t])
            {
                int t2 = 1;
                while(t)
                {
                    if(t % 10)
                        t2 *= t % 10;
                    t /= 10;
                }
                t = t2;
            }

            mem[i] = mem[t];
        }

        cnt[i][mem[i] - 1]++;
    }

    for(i = 1; i <= 1000000; i++)
        for(j = 0; j < 9; j++)
            cnt[i][j] += cnt[i - 1][j];

    int q;
    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", cnt[r][k - 1] - cnt[l - 1][k - 1]);
    }

    return 0;
}