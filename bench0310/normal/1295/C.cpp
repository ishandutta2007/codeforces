#include <bits/stdc++.h>

using namespace std;

int main()
{
    int z;
    scanf("%d",&z);
    char s[100001];
    char t[100001];
    while(z--)
    {
        scanf("%s%s",s,t);
        int n=strlen(s);
        int m=strlen(t);
        set<int> a[26];
        for(int i=0;i<n;i++) a[s[i]-'a'].insert(i);
        int res=0;
        int idx=0;
        for(int i=0;i<m;i++)
        {
            auto it=a[t[i]-'a'].lower_bound(idx);
            if(it==a[t[i]-'a'].end())
            {
                if(idx==0)
                {
                    res=-1;
                    break;
                }
                idx=0;
                i--;
            }
            else
            {
                if(idx==0) res++;
                idx=(*it)+1;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}