#include"bits/stdc++.h"
using namespace std;
char s[65004];
int main()
{
    int n;
    cin>>n;
    scanf("%s",s);
    long long ans=0;
    for(int i=0;s[i];i++)
    {
        if((s[i]-'0')%2==0)
        {
            ans+=i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}