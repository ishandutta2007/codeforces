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

char arr[400010];
int cnt[100];

char i2c(int n)
{
    if(n < 26)
        return 'a' + n;
    if(n < 52)
        return 'A' + (n - 26);
    return '0' + (n - 52);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char t;
    int n, c, l, i, j, k, d;
    scanf("%d%s", &n, arr);
    for(i = 0; i < n; i++)
    {
        t = arr[i];
        if('a' <= t && t <= 'z')
            cnt[t - 'a']++;
        else if('A' <= t && t <= 'Z')
            cnt[t - 'A' + 26]++;
        else
            cnt[t - '0' + 52]++;
    }

    c = 0;
    for(i = 0; i < 62; i++)
        if(cnt[i] % 2)
            c++;

    for(i = 1; i <= n; i++)
    {
        if(n % i)
            continue;

        l = n / i;

        if(l % 2 == 0 && c > 0 || l % 2 == 1 && c > i)
            continue;

        printf("%d\n", i);
        for(j = 0; j < i; j++)
        {
            string s;

            d = 0;
            for(k = 0; k < l / 2; k++)
            {
                for(; d < 62; d++)
                {
                    if(cnt[d] >= 2)
                    {
                        cnt[d] -= 2;
                        s.push_back(i2c(d));
                        break;
                    }
                }
            }

            printf("%s", s.c_str());

            if(l % 2 == 1)
            {
                bool u = 1;
                for(d = 0; d < 62; d++)
                {
                    if(cnt[d] % 2)
                    {
                        u = 0;
                        cnt[d]--;
                        printf("%c", i2c(d));
                        break;
                    }
                }
                if(u)
                {
                    for(d = 0; d < 62; d++)
                    {
                        if(cnt[d])
                        {
                            u = 0;
                            cnt[d]--;
                            printf("%c", i2c(d));
                            break;
                        }
                    }
                }
            }

            reverse(s.begin(), s.end());
            printf("%s ", s.c_str());
        }

        return 0;
    }
    return 0;
}