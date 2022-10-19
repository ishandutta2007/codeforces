#include"bits/stdc++.h"
using namespace std;
int n;
char s[200005];
int suma,sumb;
int qa,qb;
int main()
{
    cin>>n;
    scanf("%s",s);
    for(int i=0;i<n/2;i++)if(s[i]=='?')qa++;else suma+=s[i]-'0';
    for(int i=n/2;i<n;i++)if(s[i]=='?')qb++;else sumb+=s[i]-'0';
    suma+=(qa/2)*9;
    sumb+=(qb/2)*9;//cout<<suma<<endl<<sumb<<endl;
    qa%=2;
    qb%=2;//cout<<qa<<endl<<qb<<endl;
    if(qa==qb)
    {
        if(suma==sumb)cout<<"Bicarp"<<endl;
        else cout<<"Monocarp"<<endl;
    }
    else cout<<"Monocarp"<<endl;
    return 0;
}