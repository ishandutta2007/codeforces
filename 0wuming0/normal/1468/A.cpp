#include"bits/stdc++.h"
using namespace std;
struct node
{
    int l,r;
    node *lchild,*rchild;
    int ans;
};
int a[500006];
void creat(node &p)
{
    p.lchild=p.rchild=NULL;
    if(p.l==p.r)
    {
        p.ans=a[p.l];
        return;
    }
    p.lchild=new node;
    p.rchild=new node;
    int x=p.l+p.r>>1;
    p.lchild->l=p.l;p.lchild->r=x;
    p.rchild->l=x+1;p.rchild->r=p.r;
    creat(*p.lchild);
    creat(*p.rchild);
    p.ans=max(p.lchild->ans,p.rchild->ans);
}
int fd(node &p,int l,int r)
{
    if(l>r)return -1;
    if(p.l==l&&p.r==r)return p.ans;
    int x=p.l+p.r>>1;
    if(x>=r)
    {
        return fd(*p.lchild,l,r);
    }
    else if(x<l)
    {
        return fd(*p.rchild,l,r);
    }
    else
    {
        return max(fd(*p.lchild,l,x),fd(*p.rchild,x+1,r));
    }
}
bool cmp(pair<int,int>&now,pair<int,int>&ans)
{
    if(now.first<=ans.first)return 0;
    else return 1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        node &root=*(new node);
        root.l=1;
        root.r=n;
        creat(root);
        map<int,pair<int,int> >mp;
        pair<int,int>pr;
        #define pos second
        #define ans first
        pr.pos=0;
        pr.ans=0;
        mp[0]=pr;
        for(int i=1;i<=n;i++)
        {//for(auto pr:mp)cout<<"<<<<<<<"<<i<<" "<<pr.first<<"<<<"<<pr.second.ans<<endl;
            auto it=mp.upper_bound(a[i]);
            it--;//if(it!=mp.end())cout<<">>"<<i<<" "<<it->first<<endl;
            pr.ans=(it->second).ans+1;
            pr.pos=i;//cout<<i<<"<<<"<<(it->second).pos+1<<endl;
            if(fd(root,(it->second).pos+1,i-1)>=it->first)pr.ans++;
            if(it!=mp.begin())
            {
                it--;
                int ans2=(it->second).ans+1;
                if(fd(root,(it->second).pos+1,i-1)>=it->first)ans2++;
                if(ans2>pr.ans)pr.ans=ans2;
            }
            while(1)
            {
                auto its=mp.lower_bound(a[i]);
                if(its==mp.end())break;
                if(cmp(pr,its->second))
                {
                    mp.erase(its);
                }
                else break;
            }
            if(mp.find(a[i])==mp.end())mp[a[i]]=pr;
        }
        int sum=0;
        for(auto pr:mp)
        {
            int now=pr.second.ans;
            if(fd(root,pr.second.pos+1,n)>=pr.first)now++;
            sum=max(sum,now);
        }
        cout<<sum<<endl;
    }
    return 0;
}