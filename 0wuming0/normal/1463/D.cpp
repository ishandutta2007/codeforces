#include"bits/stdc++.h"
using namespace std;
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        map<int,int>mp1,mp2;
        for(int i=1;i<=n;i++)
        {
            mp1[a[i]]=1;mp2[-a[i]]=1;
        }
        int now=1;
        for(int i=1;i<=2*n;i++)
        {
            if(a[now]==i)now++;
            else
            {
                map<int,int>::iterator it=mp1.upper_bound(i);
                if(it!=mp1.end())mp1.erase(it);
            }
        }
        now=n;
        for(int i=2*n;i>=1;i--)
        {
            if(a[now]==i)now--;
            else
            {
                map<int,int>::iterator it=mp2.upper_bound(-i);
                if(it!=mp2.end())mp2.erase(it);
            }
        }
        cout<<n-mp2.size()-mp1.size()+1<<endl;
    }

    return 0;
}