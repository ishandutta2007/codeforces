#include"bits/stdc++.h"
using namespace std;
char s[1000005];
int n;
int main()
{
    scanf("%s",s+2);
    n=strlen(s+2);
    int now=n+1,ans=0;
    while(1)
    {//cout<<now<<endl;
        while(s[now]=='0')now--;
        if(s[now]==0)break;
        int m=now;
        while(s[m]=='1')m--;
        if(m+1==now)ans++,now=m;
        else
        {
            s[m]='1';
            now=m;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}