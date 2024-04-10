#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    char s[501];
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        vector<bool> v(26,0);
        int now=0;
        while(now<n)
        {
            char t=s[now];
            int cnt=0;
            while(now<n&&s[now]==t)
            {
                cnt++;
                now++;
            }
            if(cnt&1) v[t-'a']=1;
        }
        for(int i=0;i<26;i++) if(v[i]) printf("%c",i+'a');
        printf("\n");
    }
    return 0;
}