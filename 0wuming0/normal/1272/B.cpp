#include"bits/stdc++.h"
using namespace std;
char s[100005];
int a,b,c,d;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        a=b=c=d=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='U')a++;
            else if(s[i]=='D')b++;
            else if(s[i]=='L')c++;
            else if(s[i]=='R')d++;
        }/*
        if(a+b==0)
        {
            if(c==0||d==0)
            {
                cout<<c+d<<endl;
                for(int i=0;i<c;i++)putchar('L');
                for(int i=0;i<d;i++)putchar('R');
            }
            else
            {
                cout<<max(c,d)+1<<endl;
                if(c>d)
                {
                    putchar('R');
                    for(int i=0;i<c;i++)putchar('L');
                }
                else
                {
                    putchar('L');
                    for(int i=0;i<d;i++)putchar('R');
                }
            }
        }
        else if(c+d==0)
        {
            if(a==0||b==0)
            {
                cout<<a+b<<endl;
                for(int i=0;i<a;i++)putchar('U');
                for(int i=0;i<b;i++)putchar('D');
            }
            else
            {
                cout<<max(a,b)+1<<endl;
                if(a>b)
                {
                    putchar('D');
                    for(int i=0;i<a;i++)putchar('U');
                }
                else
                {
                    putchar('U');
                    for(int i=0;i<b;i++)putchar('D');
                }
            }
        }
        else
        {
            cout<<a+b+c+d<<endl;
            if(a>b)for(int i=0;i<b;i++)putchar('D');
            else for(int i=0;i<a;i++)putchar('U');
            if(c>d)for(int i=0;i<c;i++)putchar('L');
            else for(int i=0;i<d;i++)putchar('R');
            if(a<=b)for(int i=0;i<b;i++)putchar('D');
            else for(int i=0;i<a;i++)putchar('U');
            if(c<=d)for(int i=0;i<c;i++)putchar('L');
            else for(int i=0;i<d;i++)putchar('R');
        }*/
        if(a==0||b==0)
        {
            if(c==0||d==0)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<2<<endl;
                putchar('R');
                putchar('L');
            }
        }
        else if(c==0||d==0)
        {
            if(a==0||b==0)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<2<<endl;
                putchar('D');
                putchar('U');
            }
        }
        else
        {
            cout<<min(a,b)*2+min(c,d)*2<<endl;
            for(int i=0;i<min(a,b);i++)putchar('D');
            for(int i=0;i<min(c,d);i++)putchar('L');
            for(int i=0;i<min(a,b);i++)putchar('U');
            for(int i=0;i<min(c,d);i++)putchar('R');
        }
        putchar(10);
    }
    return 0;
}