#include"bits/stdc++.h"
using namespace std;
char s[1005];
int main()
{
    char a[30],b[30];
    cin>>a>>b;
    map<char,char>mp;
    for(int i=0;i<26;i++)
    {
        mp[a[i]]=b[i];
        mp[a[i]-'a'+'A']=b[i]-'a'+'A';
    }
    cin>>s;
    for(int i=0;s[i];i++)if(mp.find(s[i])!=mp.end())s[i]=mp[s[i]];
    cout<<s<<endl;
    return 0;
}