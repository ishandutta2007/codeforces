#include"bits/stdc++.h"
using namespace std;
int n,m;
int a[105];
int judge(int x)
{
    if(x==0)return 1;
    int sum=0;
    for(int i=0;i<105;i++)
        sum+=a[i]/x;
    if(sum>=n)return 1;
    return 0;
}
int main()
{
    cin>>n>>m;
    int t;
    for(int i=0;i<m;i++)scanf("%d",&t),a[t]++;
    int x,x1=0,x2=101;
    while(x1+1!=x2)
    {
        x=(x1+x2)/2;
        if(judge(x))x1=x;
        else x2=x;
    }
    cout<<x1<<endl;
    return 0;
}