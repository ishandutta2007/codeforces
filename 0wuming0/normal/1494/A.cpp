#include"bits/stdc++.h"
using namespace std;
char s[105];
char s2[105];
int check()
{
    int w=0;
    for(int i=0;s2[i];i++)
    {
        if(s2[i]=='(')w++;
        else w--;
        if(w<0)return 0;
    }
    if(w==0)return 1;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;s[i];i++)
        {
            if(s[i]=='A')s2[i]='(';
            if(s[i]=='B')s2[i]='(';
            if(s[i]=='C')s2[i]=')';
        }s2[n]=0;
        if(check())
        {cout<<"yes"<<endl;goto ne;
        }
        for(int i=0;s[i];i++)
        {
            if(s[i]=='A')s2[i]='(';
            if(s[i]=='B')s2[i]=')';
            if(s[i]=='C')s2[i]='(';
        }s2[n]=0;
        if(check())
        {cout<<"yes"<<endl;goto ne;
        }
                for(int i=0;s[i];i++)
        {
            if(s[i]=='A')s2[i]=')';
            if(s[i]=='B')s2[i]='(';
            if(s[i]=='C')s2[i]='(';
        }s2[n]=0;
        if(check())
        {cout<<"yes"<<endl;goto ne;
        }
                for(int i=0;s[i];i++)
        {
            if(s[i]=='A')s2[i]='(';
            if(s[i]=='B')s2[i]='(';
            if(s[i]=='C')s2[i]='(';
        }s2[n]=0;
        if(check())
        {cout<<"yes"<<endl;goto ne;
        }
                for(int i=0;s[i];i++)
        {
            if(s[i]=='A')s2[i]=')';
            if(s[i]=='B')s2[i]=')';
            if(s[i]=='C')s2[i]='(';
        }s2[n]=0;
        if(check())
        {cout<<"yes"<<endl;goto ne;
        }
                for(int i=0;s[i];i++)
        {
            if(s[i]=='A')s2[i]='(';
            if(s[i]=='B')s2[i]=')';
            if(s[i]=='C')s2[i]=')';
        }s2[n]=0;
        if(check())
        {cout<<"yes"<<endl;goto ne;
        }
                for(int i=0;s[i];i++)
        {
            if(s[i]=='A')s2[i]=')';
            if(s[i]=='B')s2[i]='(';
            if(s[i]=='C')s2[i]=')';
        }s2[n]=0;
        if(check())
        {cout<<"yes"<<endl;goto ne;
        }
        cout<<"no"<<endl;
        ne:;
    }
    return 0;
}