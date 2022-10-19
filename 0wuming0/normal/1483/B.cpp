#include"bits/stdc++.h"
using namespace std;
#define next satggea
int a[100005];
int next[100005];
int del[100005];
list<int>v;
int gcd(int x,int y)
{
    if(x==0||y==0)return x+y;
    return gcd(y,x%y);
}
int ans[100005],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        v.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            next[i]=i+1;
        }
        for(int i=0;i<=n;i++)del[i]=0;
        next[n]=1;
        nn=0;
        for(int i=1;i<=n;i++)
        {//cout<<"<<<<"<<i<<endl;
            if(gcd(a[i],a[next[i]])==1)
            {
                v.push_back(i);
                ans[nn++]=next[i];
                del[next[i]]=1;
                next[i]=next[next[i]];
                i++;
            }
        }/*
        if(v.size()==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(*v.begin()==1&&del[1]==1)
        {
            v.erase(v.begin());
        }*///cout<<"ok"<<endl;
        while(v.size())
        {
            //cout<<v.size()<<endl;
            for(auto it=v.begin();it!=v.end();)
            {
                if(del[*it]==1)
                {//cout<<"ok"<<1<<endl;
                    auto it2=it;
                    it2++;
                    v.erase(it);
                    it=it2;
                }
                else if(gcd(a[*it],a[next[*it]])!=1)
                {//cout<<"ok"<<2<<endl;
                    auto it2=it;
                    it2++;
                    v.erase(it);
                    it=it2;
                }
                else
                {//cout<<"ok"<<3<<endl;
                    ans[nn++]=next[*it];
                    del[next[*it]]=1;
                    next[*it]=next[next[*it]];
                    it++;
                }
            }
        }
        if(nn==0)cout<<0<<endl;
        else
        {
            cout<<nn<<" ";
            for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[i==nn-1]);
        }
    }
    return 0;
}