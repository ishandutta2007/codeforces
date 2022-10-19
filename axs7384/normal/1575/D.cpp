#include<bits/stdc++.h>
using namespace std;
int ans;
char s[100];
set<char> X;
int n;
inline void work(char a1,char a0)
{
    X.clear();
    int now=n-1;
    char nowc=a0;
    //cout<<now<<' '<<s[now]<<endl;
    if (s[now]>='0'&&s[now]<='9')
    {
        if (s[now]!=nowc)
            return;
    }
    if (s[now]=='X')
        X.insert(nowc);
    --now;
    nowc=a1;
    if (s[now]>='0'&&s[now]<='9')
    {
        if (s[now]!=nowc)
            return;
    }
    if (s[now]=='X')
        X.insert(nowc);
    if (s[0]=='0')
        return;
    if (X.size()>1)
        return;
    if (s[0]=='X')
    {
        if (!X.empty()&&*X.begin()=='0')
            return;
    }
    int sum=1,cz=0;
    for (int i=0;i<now;++i)
    {
        if (s[i]=='_')
            sum*=(i==0?9:10);
        if (s[i]=='X')
            cz=1;
    }
    if (cz&&X.empty())
    {
        if (s[0]=='X')
            sum*=9;
        else
            sum*=10;
    }
    //cout<<a1<<' '<<a0<<' '<<sum<<endl;
    ans+=sum;
}
int main()
{
    scanf("%s",s);
    n=strlen(s);
    //cout<<n<<"??"<<endl;
    if (n==1)
    {
        if (s[0]=='_'||s[0]=='0'||s[0]=='X')
            puts("1");
        else
            puts("0");
        return 0;
    }
    ans=0;
    if (s[0]=='_')
    {
        for (int i=1;i<=9;++i)
        {
            s[0]=i+'0';
            work('0','0');
            work('2','5');
            work('5','0');
            work('7','5');
        }
    }
    else
    {
        work('0','0');
        work('2','5');
        work('5','0');
        work('7','5');
    }
    cout<<ans<<endl;
    return 0;
}