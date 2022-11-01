#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        long long k;
        scanf("%d%I64d",&n,&k);
        char s[n+1];
        scanf("%s",s);
        int cnt=0;
        int idx=0;
        while(1)
        {
            while(idx<n&&s[idx]=='1')
            {
                cnt++;
                idx++;
            }
            if(idx==n) break;
            if(k>=cnt)
            {
                k-=cnt;
                idx++;
            }
            else
            {
                for(int i=0;i<k;i++) s[idx-i]='1';
                s[idx-k]='0';
                idx-=k;
                cnt-=k;
                k=0;
                break;
            }
        }
        for(int i=0;i<idx-cnt;i++) printf("0");
        for(int i=0;i<cnt;i++) printf("1");
        for(int i=idx;i<n;i++) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}