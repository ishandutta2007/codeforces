#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    scanf("%s",s+1);
    if(s[a]==s[b])cout<<0<<endl;
    else cout<<1<<endl;
    return 0;
}