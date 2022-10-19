#include"bits/stdc++.h"
using namespace std;
char s[105];
int main()
{
    cin>>s+1;
    int n=strlen(s+1);
    for(int i=3;i<=n;i++)
    {
        int ans=0;
        for(int j=0;j<3;j++)if(s[i-j]=='A')ans|=1;
        else if(s[i-j]=='B')ans|=2;
        else if(s[i-j]=='C')ans|=4;
        if(ans==7)
        {
            cout<<"yes"<<endl;
            return 0;
        }

    }
    cout<<"no"<<endl;
    return 0;
}