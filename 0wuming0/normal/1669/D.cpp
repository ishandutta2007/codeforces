#include"bits/stdc++.h"
using namespace std;
bool check(char s[],int n)
{
    if(n==0)return 1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='W')
        {
            return check(s,i)&&check(s+i+1,n-i-1);
        }
    }
    for(int i=1;i<n;i++)if(s[i]!=s[i-1])return 1;
    return 0;
}
char s[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s",s);
        if(check(s,n))cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}