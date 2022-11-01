#include<iostream>
using namespace std;
string s;int d[1010]={1},a=1;
main(){cin>>s;for(int i=1;i<s.size();i++,d[i]=1)for(int j=i,p=i-1;p>=0;j--,p-=2)d[i]=max(d[i],(s[p]==s[i])?d[p]+1:1),a=max(a,d[i]);cout<<a;}