#include"bits/stdc++.h"
using namespace std;
int a[100005],b[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        int p=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",b+i);
            if(b[i])p=i;
        }
        if(p==-1)
        {
            cout<<"yes"<<endl;
            continue;
        }
        if(a[p]<b[p])
        {
            cout<<"no"<<endl;
            continue;
        }
        int k=a[p]-b[p];
        for(int i=0;i<n;i++)
        {
            if(max(a[i]-k,0)!=b[i])
            {
                cout<<"no"<<endl;
                goto ne;
            }
        }
        cout<<"yes"<<endl;
        ne:;
    }
    return 0;
}