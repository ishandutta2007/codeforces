#include"bits/stdc++.h"
using namespace std;
char s[100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        int a=0,b=0;
        int ans=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='a')
            {
                a++;
                if(b==1)
                {
                    ans=1;
                }
                b=0;
            }
            else
            {
                b++;
                if(a==1)
                {
                    ans=1;
                }
                a=0;
            }
        }
        if(a==1||b==1)ans=1;
        if(ans)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}