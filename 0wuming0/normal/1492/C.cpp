#include"bits/stdc++.h"
using namespace std;
char s[200005];
char t[200005];
int ans[200005];
int main()
{
    int n,m;
    cin>>n>>m;
    scanf("%s",s);
    scanf("%s",t);
    for(int i=0,j=0;j<m;i++,j++)
    {
        while(s[i]!=t[j])
        {
            i++;
            if(i>=n)
            {
                return 1;
            }
        }
        ans[j]=i;
    }
    int sum=0;
    for(int i=n-1,j=m-1;j>=1;i--,j--)
    {
        while(s[i]!=t[j])
        {
            i--;
        }
        sum=max(i-ans[j-1],sum);
    }
    cout<<sum<<endl;
    return 0;
}