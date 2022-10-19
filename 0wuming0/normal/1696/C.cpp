#include"bits/stdc++.h"
using namespace std;
int a[200005],b[200005];
void add(int c,long long num,vector<pair<int,long long> >&a)
{
    if(a.size()&&a[a.size()-1].first==c)
    {
        a[a.size()-1].second+=num;
    }
    else
    {
        a.push_back(pair<int,long long>(c,num));
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,long long> >a;
        vector<pair<int,long long> >b;
        for(int i=0;i<n;i++)
        {
            int c;
            scanf("%d",&c);
            long long num=1;
            while(c%m==0)
            {
                c/=m;
                num=num*m;
            }
            add(c,num,a);
        }
        int k;
        cin>>k;
        for(int i=0;i<k;i++)
        {
            int c;
            scanf("%d",&c);
            long long num=1;
            while(c%m==0)
            {
                c/=m;
                num=num*m;
            }
            add(c,num,b);
        }
        if(a==b)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}