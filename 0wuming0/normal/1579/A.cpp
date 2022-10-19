#include"bits/stdc++.h"
using namespace std;
int num[1040];
char s[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        for(int i=0;s[i];i++)
        {
            num[s[i]]++;
        }
        if(num['A']+num['C']==num['B'])printf("YES\n");
        else printf("NO\n");
        num['A']=num['C']=num['B']=0;
    }
    return 0;
}