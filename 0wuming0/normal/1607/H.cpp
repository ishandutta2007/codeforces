#include"bits/stdc++.h"
using namespace std;
vector<int>v[2000005];
int a[200005],b[200005],m[200005];
int ans[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d%d%d",a+i,b+i,m+i);
        for(int i=0;i<n;i++)
        {
            v[a[i]+b[i]-m[i]].push_back(i);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(v[a[i]+b[i]-m[i]].size()==0)continue;
            int nn=0;
            multiset<pair<int,int> >mp;
            set<int>s;
            for(auto j:v[a[i]+b[i]-m[i]])
            {
                mp.insert(make_pair(max(a[j]-m[j],0),-j-1));
                mp.insert(make_pair(a[j]-max(m[j]-b[j],0),j+1));
            }
            while(mp.size())
            {
                auto pr=*mp.begin();
                mp.erase(mp.begin());
                if(pr.second<0)s.insert(-pr.second);
                else
                {
                    if(s.find(pr.second)==s.end())continue;
                    for(auto j:s)ans[j-1]=pr.first;
                    s.clear();
                    sum++;
                }
            }
            v[a[i]+b[i]-m[i]].clear();
        }
        cout<<sum<<endl;
        for(int i=0;i<n;i++)printf("%d %d\n",a[i]-ans[i],m[i]-a[i]+ans[i]);
    }
    return 0;
}