#include"bits/stdc++.h"
using namespace std;
struct _
{
    int a;
    int b;
    int op;
}a[200005];
bool cmp(struct _ x,struct _ y)
{
    return x.a<y.a;
}
int ans[200005];
vector<int> v[200005];
vector<int> v2[200005];
int num[200005];
int save[200005],nl,nn;
int mem[200005];
int n,m;
int solve1()
{
    for(int i=1;i<=n;i++)
    {
        if(num[i]==0)save[nn++]=i;
    }
    for(;nl<nn;nl++)
    {
        for(vector<int>::iterator it=v[save[nl]].begin();it!=v[save[nl]].end();it++)
        {
            num[*it]--;
            if(num[*it]==0)save[nn++]=(*it);
        }
    }
    if(nn!=n)
    {
        cout<<-1<<endl;
        exit(0);
    }
}
void sets(int i,int t)
{
    if(ans[i]==5)return;
    if(ans[i]==2)return;
    if(ans[i]==t)return;
    if(ans[i]==0)ans[i]=t;
    else ans[i]=2;
    if(t==1)
    for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
    {
        sets(*it,t);
    }
    if(t==-1)
    for(vector<int>::iterator it=v2[i].begin();it!=v2[i].end();it++)
    {
        sets(*it,t);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i].a);
        scanf("%d",&a[i].b);
        num[a[i].b]++;
        v[a[i].a].push_back(a[i].b);
        v2[a[i].b].push_back(a[i].a);
        a[i].op=1;
        if(a[i].a>a[i].b)
        {
            swap(a[i].a,a[i].b);
            a[i].op=-1;
        }
    }
    solve1();
    sort(a,a+m,cmp);
    int now=0;
    for(int i=1;i<=n;i++)
    {//*
        if(ans[i]==0)
        {
            int flag=1;
            for(int j=now;j<m;j++)
            {
                if(a[j].a!=i)break;
                if(ans[a[j].b]==-a[j].op||ans[a[j].b]==2)flag=0;
            }
            if(flag)ans[i]=5;
        }/*
        else
        {
            int flag=1;
            for(int j=now;j<m;j++)
            {
                if(a[j].a!=i)break;
                if(ans[a[j].b]==-a[j].op)flag=0;
            }
            if(flag)ans[i]=5;
        }*/
        for(;now<m;now++)
        {
            if(a[now].a!=i)break;
            sets(a[now].b,a[now].op);
            //ans[a[now].b]=a[now].op;
        }
        //*/
            /*
        int flag=1;
        for(;now<m;now++)
        {
            if(a[now].a!=i)break;
            flag|=ans[a[now].b];
            ans[a[now].b]=1;
        }
        if(ans[i]==0)ans[i]=(flag^1);*/
    }
    int anss=0;
    for(int i=1;i<=n;i++)if(ans[i]==5)anss++;
    cout<<anss<<endl;
    for(int i=1;i<=n;i++)putchar("EA"[ans[i]==5]);
    return 0;
}