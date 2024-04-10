#include"bits/stdc++.h"
using namespace std;
int main()
{
    int ans=0;
    int ansx,ansy;
    map<int,pair<int,int> >mp;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        mp[k]=make_pair(0,i);
    }
    while(mp.size()>1)
    {
        auto it=mp.end();
        it--;
        auto pr=*it;
        int x=it->first,y=(it->second).first+1,id=(it->second).second;
        mp.erase(it);
        for(int i=1;;i<<=1)
        {
            if(i>=x)
            {
                x=i-x;
                it=mp.find(x);
                if(it!=mp.end())
                {
                    if((it->second).first+y>ans)
                    {
                        ans=(it->second).first+y;
                        ansy=id;
                        ansx=(it->second).second;
                    }
                    it->second=max(it->second,make_pair(y,id));
                }
                else mp[x]=make_pair(y,id);
                break;
            }
        }
    }
    cout<<ansx<<" "<<ansy<<" "<<ans<<endl;
    return 0;
}