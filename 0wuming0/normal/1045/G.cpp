#include"bits/stdc++.h"
using namespace std;
long long ans;
struct node
{
    int l,r;
    int num;
    node *lchild,*rchild;
}nullnode;
map<int,set<int> >st;
map<int,int*>save;
map<int,node>mp;
struct robot
{
    int x;
    int r;
    int q;
}a[100005];
bool cmp(robot x,robot y)
{
    return x.r>y.r;
}
set<int>nullset;
void creat(node &p)
{
    int x=p.l+p.r;x/=2;
    p.num=0;
    if(p.l==p.r)
    {
        p.lchild=p.rchild=0;
        return;
    }
    p.lchild=new node;
    p.rchild=new node;
    p.lchild->l=p.l;p.lchild->r=x;
    p.rchild->l=x+1;p.rchild->r=p.r;
    creat(*p.lchild);
    creat(*p.rchild);
}
void cal(node &p,int pos[],int l,int r)
{//cout<<">>>"<<l<<" "<<r<<" "<<pos[p.l]<<" "<<pos[p.r]<<endl;
    if(pos[p.l]>l)l=pos[p.l];
    if(r>pos[p.r])r=pos[p.r];
    if(l>r)return;
    if(l==pos[p.l]&&r==pos[p.r])
    {
        ans+=p.num;
        return;
    }
    if(l<=pos[p.lchild->r])cal(*p.lchild,pos,l,r);
    if(r>=pos[p.rchild->l])cal(*p.rchild,pos,l,r);
}
void ins(node &p,int pos[],int x)
{
    p.num++;
    if(pos[p.l]==pos[p.r])
    {
        return;
    }
    else if(pos[p.lchild->r]>=x)ins(*p.lchild,pos,x);
    else ins(*p.rchild,pos,x);
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)scanf("%d%d%d",&a[i].x,&a[i].r,&a[i].q);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        auto it=st.find(a[i].q);
        if(it!=st.end())
        {
            (it->second).insert(a[i].x);
        }
        else
        {
            st[a[i].q]=nullset;
            it=st.find(a[i].q);
            (it->second).insert(a[i].x);
            save[a[i].q]=0;
            mp[a[i].q]=nullnode;
        }
    }
    {
        auto it1=st.begin();
        auto it2=save.begin();
        auto it3=mp.begin();
        for(;it1!=st.end();it1++,it2++,it3++)
        {
            it2->second=new int[(it1->second).size()];
            auto it=(it1->second).begin();
            for(int i=0;i<(it1->second).size();i++)
            {
                (it2->second)[i]=*it;
                it++;
            }
            (it3->second).l=0;
            (it3->second).r=(it1->second).size()-1;
            creat(it3->second);
        }
    }
    for(int i=0;i<n;i++)
    {
        auto it=mp.find(a[i].q);
        int *pos=(save.find(a[i].q))->second;
        for(int q=a[i].q-k;q<=a[i].q+k;q++)
        {
            it=mp.find(q);
            if(it!=mp.end())
            {//cout<<"<<<<"<<i<<" "<<a[i].q<<" "<<q<<endl;
                pos=(save.find(q))->second;
                cal(it->second,pos,a[i].x-a[i].r,a[i].x+a[i].r);
            }
        }
        pos=(save.find(a[i].q))->second;
        it=mp.find(a[i].q);
        ins(it->second,pos,a[i].x);
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 3
3 5 6
8 10 8
10 6 4
6 6 3
7 4 5
*/