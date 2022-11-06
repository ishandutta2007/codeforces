#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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

char arr1[2010];
char arr2[2010];
int cnt[26];

int n;
char tmp[2010];
void shift(int x)
{
    int i;
    for(i = 0; i < n - x; i++)
        tmp[i + x] = arr1[i];
    for(i = n - x; i < n; i++)
        tmp[n - 1 - i] = arr1[i];
    for(i = 0; i < n; i++)
        arr1[i] = tmp[i];

    printf("%d ", x);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int i, j;
    scanf("%d%s%s", &n, arr1, arr2);

    for(i = 0; i < n; i++)
    {
        cnt[arr1[i] - 'a']++;
        cnt[arr2[i] - 'a']--;
    }
    for(i = 0; i < 26; i++)
    {
        if(cnt[i])
        {
            printf("-1\n");
            return 0;
        }
    }

    vector<char> lis;
    if(n % 2 == 1)
    {
        lis.push_back(arr2[n / 2]);
        for(i = 1; i <= n / 2; i++)
        {
            lis.push_back(arr2[n / 2 - i]);
            lis.push_back(arr2[n / 2 + i]);
        }
    }
    else
    {
        for(i = 0; i < n / 2; i++)
        {
            lis.push_back(arr2[n / 2 - 1 - i]);
            lis.push_back(arr2[n / 2 + i]);
        }
    }

    printf("%d\n", 3 * n);
    for(i = 0; i < n; i++)
    {
        for(j = n - 1; j >= 0; j--)
        {
            if(arr1[j] == lis[i])
            {
                shift(n - j);
                shift(j - i);
                shift(n);
                break;
            }
        }
    }

    return 0;
}