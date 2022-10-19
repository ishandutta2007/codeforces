#include"bits/stdc++.h"
using namespace std;
char s[400005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int n;
        scanf("%s",s);
        n=strlen(s);
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            if(s[i]!='?'&&s[j]!='?')
            {
                if(s[i]!=s[j])
                {
                    cout<<-1<<endl;
                    goto ne;
                }
                if(s[i]=='0')a-=2;
                else b-=2;
            }
            else if(s[i]==s[j])continue;
            else if(s[i]=='0'||s[j]=='0')
            {
                s[i]=s[j]='0';
                a-=2;
            }
            else
            {
                s[i]=s[j]='1';
                b-=2;
            }
        }
        if(a<0||b<0)
        {
            cout<<-1<<endl;
            goto ne;
        }
        if(a%2==1&&b%2==1)
        {
            cout<<-1<<endl;
            goto ne;
        }
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            if(s[i]=='?')
            {
                if(a>1)
                {
                    s[i]=s[j]='0';
                    a-=2;
                }
                else
                {
                    s[i]=s[j]='1';
                    b-=2;
                }
            }
        }
        if(a==1)
        {
            if(s[n/2]=='1')
            {
                cout<<-1<<endl;
                goto ne;
            }
            s[n/2]='0';
        }
        else if(b==1)
        {
            if(s[n/2]=='0')
            {
                cout<<-1<<endl;
                goto ne;
            }
            s[n/2]='1';
        }
        printf("%s\n",s);
        ne:;
    }
    return 0;
}