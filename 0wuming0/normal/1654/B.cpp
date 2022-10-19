#include"bits/stdc++.h"
using namespace std;
int num[1005];
char s[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(num,0,sizeof(num));
        scanf("%s",s);
        for(int i=0;s[i];i++)num[s[i]]++;
        for(int i=0;s[i];i++)
        {
            num[s[i]]--;
            if(num[s[i]]==0)
            {
                printf("%s\n",s+i);
                break;
            }
        }
    }
    return 0;
}