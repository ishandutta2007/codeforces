#include <bits/stdc++.h>
using namespace std;
#define N (300*1000)
int n,ans=1,a[N],b[N];
pair <int,int> p[N];
int main()
{ 

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        p[i]={a[i]+b[i],i};
    }
    sort(p,p+n);
    int last=p[0].first;
    for(int i=1;i<n;i++)
    {
        int index=p[i].second;
        if(last<=a[index]-b[index])
            ans++,last=p[i].first;
    }
    cout<<ans;
    return 0;
}