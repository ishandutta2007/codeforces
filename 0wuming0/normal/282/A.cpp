#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    int ans=0;
    while(t--)
    {
        char s[10];
        scanf("%s",s);
        if(s[0]=='+'||s[2]=='+')ans++;
        else ans--;
    }
    cout<<ans<<endl;
    return 0;
}