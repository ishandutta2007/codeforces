#include <bits/stdc++.h>
using namespace std;

long long way[10000000][2],step[10000000],kilk,n,x;
char c;
string sch2(long long x)
{
    string ans="";
    while (x!=0)
    {
        ans+=char(x%2+'0');
        x/=2;
    }
    while (ans.size()<32)
    {
        ans+='0';
    }
    reverse(ans.begin(),ans.end());
    return(ans);
}
void add(string st)
{
    long long tep=0;
    for (int i=0;i<st.size();i++)
    {
        if (way[tep][st[i]-'0']==0)
            way[tep][st[i]-'0']=++kilk;
        tep=way[tep][st[i]-'0'];
        step[tep]++;
    }
}
void del(string st)
{
    long long tep=0;
    for (int i=0;i<st.size();i++)
    {
        tep=way[tep][st[i]-'0'];
        step[tep]--;
    }
}
string xorr(string st)
{
    for (int i=0;i<st.size();i++)
        if (st[i]=='1') st[i]='0'; else st[i]='1';
    long long tep=0;
    string ans="";
    for (int i=0;i<st.size();i++)
    {
        if (step[way[tep][st[i]-'0']]>0)
        {
            ans+='1';
            tep=way[tep][st[i]-'0'];
        } else
        {
            ans+='0';
            tep=way[tep][!(st[i]-'0')];
        }
    }
    return(ans);
}
long long perev(string st)
{
    long long h=1,ans=0;
    for (int i=st.size()-1;i>=0;i--)
    {
        ans+=(st[i]-'0')*h;
        h*=2;
    }
    return(ans);
}
int main()
{
    cin>>n;
    add(sch2(0));
    while (n--)
    {
        cin>>c;
        if (c=='+')
        {
            cin>>x;
            string st=sch2(x);
            add(st);
        }
        if (c=='-')
        {
            cin>>x;
            string st=sch2(x);
            del(st);
        }
        if (c=='?')
        {
            cin>>x;
            string st=sch2(x);
            string ans=xorr(st);
            cout<<perev(ans)<<'\n';
        }
    }
}