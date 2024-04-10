#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char s[N],t[N];
int a[N];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",s+1,t+1);
        int n=strlen(s+1),m=strlen(t+1);
        for  (int i=0;i<=25;++i)
            a[i]=0;
        for (int i=1;i<=m;++i)
            ++a[t[i]-'A'];
        int now=m;
        for (int i=n;i>=1;--i)
            if (a[s[i]-'A'])
            {
                if (s[i]==t[now])
                    --now;
                else
                    now=-1;
                if (now<=0)
                    break;
                --a[s[i]-'A'];
            }
        puts(now==0?"YES":"NO");
    }
    return 0;
}