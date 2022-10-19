#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,c;
        cin>>n>>x;
        multiset<int>a,b;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&c);
            a.insert(c);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&c);
            b.insert(-c);
        }
        for(auto k:a)
        {//for(auto kk:b)cout<<kk;cout<<endl;
            auto it=b.lower_bound(k-x);//cout<<k-x<<" "<<*it<<endl;
            if(it==b.end())
            {
                cout<<"no"<<endl;
                goto ed;
            }
            b.erase(it);
        }
        cout<<"yes"<<endl;
        ed:;
    }
    return 0;
}