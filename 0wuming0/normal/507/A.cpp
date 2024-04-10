#include"bits/stdc++.h"
using namespace std;
int a[105],pos[105];
int cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {scanf("%d",a+i);
    pos[i]=i;
    }
    sort(pos,pos+n,cmp);
    int sum=0,num=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[pos[i]];
        if(sum<=k)num++;
        else break;
    }
    cout<<num<<endl;
    for(int i=0;i<num;i++)
        cout<<pos[i]+1<<" \n"[i==num-1];
    return 0;
}