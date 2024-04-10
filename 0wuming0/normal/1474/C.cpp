#include"bits/stdc++.h"
using namespace std;
int pos[2005];
int a[2005];
int ans[2005][2],nn;
void add(int x,int y)
{
    ans[nn][0]=min(x,y);
    ans[nn][1]=max(x,y);
    nn++;
}
int cmp(int x,int y)
{
    return a[x]<a[y];
}
void add(map<int ,int >&a,int x)
{
    map<int ,int >::iterator it=a.find(x);
    if(it==a.end())
    {
        a[x]=1;
    }
    else
    {
        it->second++;
    }
}
void del(map<int ,int >&a,int x)
{
    map<int ,int >::iterator it=a.find(x);
        it->second--;
        if(it->second==0)a.erase(it);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n*=2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            pos[i]=i;
        }
        sort(pos+1,pos+1+n,cmp);
        nnas:;
        for(int j=1;j<n;j++)
        {
            nn=0;
            map<int ,int >m;
            for(int i=1;i<=n;i++)add(m,-a[i]);
            del(m,-a[pos[j]]);
            int big=a[pos[n]];
            map<int ,int >::iterator it=m.find(-big),it2;
            del(m,-big);
            add(a[pos[j]],big);
            while(m.size()!=0)
            {
                it=m.lower_bound(-big);//cout<<it->first<<endl;
                it2=m.find(-(big-(-it->first)));
                if(it2==m.end())goto eddd;
                if(it->first==it2->first&&it2->second==1)goto eddd;
                add(-it->first,-it2->first);//cout<<(-it->first)<<"  "<<(-it2->first)<<"  "<<m.size()<<endl;
                big=-it->first;
                del(m,it->first);
                del(m,it2->first);
            }
            it=m.lower_bound(-big);
            //ans[0][0]=-it->first;
            cout<<"YES"<<endl;
            cout<<ans[0][0]+ans[0][1]<<endl;
            for(int i=0;i<nn;i++)
            {
                cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
            }
            goto ne;
            eddd:;
        }
        cout<<"NO"<<endl;
        ne:;
    }
    return 0;
}