#include"bits/stdc++.h"
using namespace std;
int main()
{
    char s[100006];
    scanf("%s",s);
    int n1=0,n2=0;//cout<<(int)(s[0])<<endl;
    for(int i=1;s[i];i++)
    {
        if(s[i-1]=='A'&&s[i]=='B')n1++;
        if(s[i]=='A'&&s[i-1]=='B')n2++;
    }//cout<<n1<<n2<<endl;
    if(n1&&n2&&(n1+n2)>3)cout<<"YES"<<endl;
    else if(n1==0||n2==0)cout<<"NO"<<endl;
    else if(n1+n2==3)
    {
        int a=0,b=0,c=0,d=0;
        for(int i=3;s[i];i++)
        {
            if(s[i-3]=='A'&&s[i-2]=='B'&&s[i-1]=='A'&&s[i]=='B')
            {
                cout<<"NO"<<endl;return 0;
            }
            if(s[i-3]=='B'&&s[i-2]=='A'&&s[i-1]=='B'&&s[i]=='A')
            {
                cout<<"NO"<<endl;return 0;
            }

        }cout<<"YES"<<endl;
    }
    else if(n1+n2==2)
    {
        int a=0,b=0,c=0,d=0;
        for(int i=2;s[i];i++)
        {
            if(s[i-2]=='B'&&s[i-1]=='A'&&s[i]=='B')
            {
                cout<<"NO"<<endl;return 0;
            }
            if(s[i-2]=='A'&&s[i-1]=='B'&&s[i]=='A')
            {
                cout<<"NO"<<endl;return 0;
            }

        }cout<<"YES"<<endl;
    }
    return 0;
}