#include"bits/stdc++.h"
using namespace std;
int ans[2005],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>odd,even;
        for(int i=1;i<=2*n;i++)
        {
            int a;
            scanf("%d",&a);
            if(a%2)odd.push_back(i);
            else even.push_back(i);
        }
        int flag=0;
        nn=0;
        for(auto a:odd)
        {
            if(flag==0)ans[nn]=a;
            else
            {
                nn++;
                ans[nn++]=a;
            }
            flag^=1;
        }
        flag=0;
        for(auto a:even)
        {
            if(flag==0)ans[nn]=a;
            else
            {
                nn++;
                ans[nn++]=a;
            }
            flag^=1;
        }
        for(int i=0;i<2*n-2;i++)printf("%d%c",ans[i]," \n"[i%2]);
    }
    return 0;
}