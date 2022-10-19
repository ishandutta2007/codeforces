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
        for(int i=0;i<n;i++)scanf("%d",a+i);
        int i=0,j=n-1;
        for(;i<j;i++,j--)
        {
            if(a[i]!=a[j])break;
        }
        vector<int>v;
        if(i<j)
        {
            for(int k=0;k<n;k++)if(a[k]!=a[i])
            {
                v.push_back(a[k]);
            }
            for(int i=0,j=v.size()-1;i<j;i++,j--)if(v[i]!=v[j])
            {
                goto ad;
            }
            cout<<"YES"<<endl;
            goto ne;
            ad:;
            v.clear();
            for(int k=0;k<n;k++)if(a[k]!=a[j])
            {
                v.push_back(a[k]);
            }
            for(int i=0,j=v.size()-1;i<j;i++,j--)if(v[i]!=v[j])
            {
                goto adf;
            }
            cout<<"YES"<<endl;
            goto ne;
            adf:;
            cout<<"NO"<<endl;
            goto ne;
        }
        cout<<"YES"<<endl;
        ne:;
    }
    return 0;
}