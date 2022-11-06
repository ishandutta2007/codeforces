#include <bits/stdc++.h>

using namespace std;

string arr[100010];
char buf[500010];

int cnt1[500010];
int cnt2[500010];

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", buf);
        arr[i] = buf;
    }

    for(i = 0; i < n; i++)
    {
        int l = arr[i].size();

        int c = 0;
        bool ok = 1;
        for(j = 0; j < l; j++)
        {
            if(arr[i][j] == '(')
                c++;
            else
                c--;

            if(c < 0)
            {
                ok = 0;
                break;
            }
        }
        if(ok)
            cnt1[c]++;
        else
        {
            int c = 0;
            bool ok = 1;
            for(j = l - 1; j >= 0; j--)
            {
                if(arr[i][j] == ')')
                    c++;
                else
                    c--;

                if(c < 0)
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
                cnt2[c]++;
        }
    }

    int res = cnt1[0] / 2;
    for(i = 1; i <= 500010; i++)
        res += min(cnt1[i], cnt2[i]);

    printf("%d\n", res);
    return 0;
}