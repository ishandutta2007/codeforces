#include"bits/stdc++.h"
using namespace std;
int a[200005];
int n;
int pos[200005];
int save[200005],nn;
bool cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            pos[i]=i;
            scanf("%d",a+i);
        }
        sort(pos,pos+n,cmp);
        int ans=0;
        long long sum=a[pos[0]];
        for(int i=1;i<n;i++)
        {
            if(sum<a[pos[i]])ans=i;
            sum+=a[pos[i]];
        }
        nn=0;
        for(int i=0;i<n;i++)if(a[i]>=a[pos[ans]])
        {
            save[nn++]=i+1;
        }
        cout<<nn<<endl;
        for(int i=0;i<nn;i++)printf("%d%c",save[i]," \n"[i==nn-1]);
    }
    return 0;
}