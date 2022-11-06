#include <bits/stdc++.h>
using namespace std;

vector<char> v;
char arr[110][110];
int val[100];

void solve()
{
    int r, c, k;
    scanf("%d%d%d", &r, &c, &k);
    for(int i = 0; i < r; i++)
        scanf("%s", arr[i]);

    int cnt = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(arr[i][j] == 'R')
                cnt++;

    for(int i = 0; i < k; i++)
        val[i] = 0;
    for(int i = 0; i < cnt; i++)
        val[i % k]++;

    int idx = 0;
    int cur = 0;
    for(int i = 0; i < r; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < c; j++)
            {
                if(arr[i][j] == 'R')
                    cur++;

                arr[i][j] = v[idx];

                if(cur >= val[idx] && idx + 1 < k)
                {
                    idx++;
                    cur = 0;
                }
            }
        }
        else
        {
            for(int j = c - 1; j >= 0; j--)
            {
                if(arr[i][j] == 'R')
                    cur++;

                arr[i][j] = v[idx];

                if(cur >= val[idx] && idx + 1 < k)
                {
                    idx++;
                    cur = 0;
                }
            }
        }
    }

    for(int i = 0; i < r; i++)
        printf("%s\n", arr[i]);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    for(int i = 0; i < 26; i++)
        v.push_back('a' + i);
    for(int i = 0; i < 26; i++)
        v.push_back('A' + i);
    for(int i = 0; i < 10; i++)
        v.push_back('0' + i);

    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        solve();
    
    return 0;
}