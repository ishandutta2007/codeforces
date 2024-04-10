#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        multimap<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);if(a)
            mp.insert(make_pair(a,i));
        }
        vector<pair<int,int> >v;
        while(mp.size()>=2)
        {
            auto it=mp.end();it--;
            pair<int,int> a=*it;
            mp.erase(it);
            it=mp.end();it--;
            pair<int,int> b=*it;
            mp.erase(it);
            a.first--;b.first--;
            v.push_back(make_pair(a.second,b.second));
            if(a.first)mp.insert(a);
            if(b.first)mp.insert(b);
        }
        cout<<v.size()<<endl;
        for(auto pr:v)
        {
            printf("%d %d\n",pr.first,pr.second);
        }
    }
    return 0;
}