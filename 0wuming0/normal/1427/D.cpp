#include"bits/stdc++.h"
using namespace std;
int a[100];
int pos[100];
int n;
vector<vector<int> >v;
bool solve()
{//for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
    int flag=0;
    for(int i=1;i<=n;i++)if(a[i]!=i)flag=1;
    if(flag==0)return 0;
    for(int i=1;i<=n;i++)pos[a[i]]=i;
    int now=-1;
    for(int i=1;i<=n;i++)
    {
        if(pos[i]+1!=pos[i+1]&&pos[i]>pos[i+1])
        {
            now=i;
            break;
        }
    }
    vector<int>ans;
    if(pos[now]>pos[now+1])
    {
        if(pos[now+1]-1)ans.push_back(pos[now+1]-1);
        int aa=1,bb=pos[now]-pos[now+1],cc=pos[now+1];
        while(a[cc]+1==a[cc+1])
        {
            aa++;
            bb--;
            cc++;
        }
        ans.push_back(aa);
        if(bb)ans.push_back(bb);
        if(n-pos[now])ans.push_back(n-pos[now]);
    }
    else
    {
        for(int i=1;i<=n;i++)ans.push_back(1);
    }
    {
        int now=n;
        vector<int>s;
        for(int i=ans.size()-1;i>=0;i--)
        {
            int k=ans[i];
            for(int i=now-k+1;i<=now;i++)
            {
                s.push_back(a[i]);
            }
            now-=k;
        }
        now=1;
        for(auto c:s)
        {
            a[now++]=c;
        }
    }
    v.push_back(ans);
    return 1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    while(solve());
    cout<<v.size()<<endl;
    for(auto a:v)
    {
        cout<<a.size();
        for(auto c:a)
        {
            printf(" %d",c);
        }
        cout<<endl;
    }
    return 0;
}