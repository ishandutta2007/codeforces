#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            m[a[i]]=1;
        }
        cout<<m.size()<<endl;
    }
    return 0;
}