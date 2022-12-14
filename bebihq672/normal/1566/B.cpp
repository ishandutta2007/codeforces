#include<bits/stdc++.h>
using namespace std;

char s[101010];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int cnt0 = 0, cnt1 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(s[i] == '0' && s[i - 1] != '0')
                cnt0++;
            if(s[i] == '1')
                cnt1 = 1;
        }
        if(cnt0 == 0)
        {
            puts("0");
        }
        else if(cnt0 == 1)
            puts("1");
        else
            puts("2");
    }
    return 0;
}