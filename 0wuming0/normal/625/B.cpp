#include"bits/stdc++.h"
using namespace std;
int main()
{
    char s[1000005],t[100];
    scanf("%s%s",s,t);
    int ans=0;
    for(int i=0;s[i];i++)
    {
        for(int j=0;t[j];j++)
        {
            if(s[i+j]!=t[j])break;
            if(t[j+1]==0)
            {
                ans++;
                i+=j;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}