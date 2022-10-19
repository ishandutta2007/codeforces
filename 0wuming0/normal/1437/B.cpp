#include"bits/stdc++.h"
using namespace std;
int main()
{
    char s[100005];
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s",s);
        int ans=0;
        for(int i=1;;i++)
        {
            if(s[i]==0)
            {
                if(s[0]==s[i-1]&&s[0]=='0')ans++;
                break;
            }
            if(s[i]==s[i-1]&&s[i]=='0')ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}