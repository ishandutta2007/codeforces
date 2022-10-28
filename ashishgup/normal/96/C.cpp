#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
char ch;
string s;
string a[105];
bool origcaps[105], check[105];

void work(string &str)
{
    int a=s.size(), b=str.size();
    for(int i=0;i+b-1<a;i++)
    {
        if(s.substr(i, b)==str)
        {
            for(int j=i;j<=i+b-1;j++)
                check[j]=1;
        }
    }
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(auto &it:a[i])
            it=tolower(it);
    }
    cin>>s>>ch;
    int sz=s.size();
    for(int i=0;i<sz;i++)
    {
        if(isupper(s[i]))
        {
            origcaps[i]=1;
            s[i]=tolower(s[i]);
        }
    }
    for(int i=1;i<=n;i++)
        work(a[i]);
    for(int i=0;i<sz;i++)
    {
        if(check[i])
        {
            if(s[i]==ch)
            {
                s[i]='a';
                while(s[i]==ch)
                    s[i]++;
            }
            else
                s[i]=ch;
        }
        if(origcaps[i])
            s[i]=toupper(s[i]);
    }
    cout<<s;
    return 0;
}