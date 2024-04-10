#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int nn=0;
        s[n]=0;
        if(n<=26)
        {
            for(int i=0;i<n;i++)
            {
                s[i]='a'+i;
            }
        }
        else
        {
            for(int i=0;i<n/2-1;i++)
            {
                s[nn++]='b';
            }
            s[nn++]='a';
            for(int i=0;i<n/2;i++)
            {
                s[nn++]='b';
            }
            char c='c';
            while(nn!=n)
            {
                s[nn++]=c++;
            }
        }
        printf("%s\n",s);
    }
    return 0;
}