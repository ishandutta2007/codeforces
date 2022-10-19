#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[200006],b[200006];
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0;i<n;i++)b[i]=a[i];
    int now=a[0],h=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=now+2);
        else
        {
            h++;
            now=a[i];i--;
        }

    }
    cout<<h<<" ";h=0;
    a[0]--;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1]+1)a[i];
        else if(a[i]==a[i-1])a[i]++;
        else if(a[i]<a[i-1])a[i]=a[i-1],h++;else
        {
            a[i]--;
        }

    }
    now=a[0];h=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=now)now=a[i],h++;
    }
    cout<<h<<endl;
    return 0;
}