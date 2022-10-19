#include"bits/stdc++.h"
using namespace std;
char s[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        int last=-10;
        int n=strlen(s);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {//cout<<j<<" "<<s[j]<<endl;
                if(s[j]=='1')
                {
                    if(last+1==j)goto ne;
                    last=j;
                }
            }
            for(int j=i;j<n;j++)
            {//cout<<j<<" "<<s[j]<<endl;
                if(s[j]=='0')
                {//cout<<"!"<<j<<endl;
                    if(last+1==j)goto ne;
                    last=j;
                }
            }
            //cout<<i<<endl;
            cout<<"yes"<<endl;
            goto nee;
            ne:;
        }
        cout<<"no"<<endl;
        nee:;
    }
    return 0;
}