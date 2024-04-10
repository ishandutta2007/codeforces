#include"bits/stdc++.h"
using namespace std;
struct edge
{
    int l;
    int r;
    int num;
};
int visedge[100005];
vector<struct edge>v[100005];
struct node
{
    int num;
    struct node* next;
};
int pos[100005][3],nn;
int vis[100005];
int num[100005];
struct node* savenode[100005];
void solve(int i)
{
    for(vector<struct edge>::iterator it=v[i].begin();it!=v[i].end();++it)
    {
        if(visedge[it->num]==0)
        {
            pos[nn][0]=i;
            pos[nn][1]=it->l;
            pos[nn][2]=it->r;
            vis[nn]=it->num;
            nn++;
            visedge[it->num]=1;
            num[i]--;
            num[it->l]--;
            num[it->r]--;
            if(num[it->l]==1)solve(it->l);
            if(num[it->r]==1)solve(it->r);
            break;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n-2;i++)
        {
            int a,b,c;
            scanf("%d",&a);
            scanf("%d",&b);
            scanf("%d",&c);
            num[a]++;
            num[b]++;
            num[c]++;
            edge e;
            e.num=i;
            e.l=b;e.r=c;v[a].push_back(e);
            e.l=c;e.r=a;v[b].push_back(e);
            e.l=a;e.r=b;v[c].push_back(e);
        }
        for(int i=1;i<=n;i++)
        {
            if(num[i]==1)
            {
                solve(i);
            }
        }
        for(int i=0,j=nn-1;i<j;i++,j--)
        {
            for(int k=0;k<3;k++)
                swap(pos[i][k],pos[j][k]);
        }
        savenode[pos[0][0]]=new node;
        savenode[pos[0][1]]=new node;
        savenode[pos[0][2]]=new node;
        for(int i=0;i<3;i++)savenode[pos[0][i]]->num=pos[0][i];
        savenode[pos[0][0]]->next=savenode[pos[0][1]];
        savenode[pos[0][1]]->next=savenode[pos[0][2]];
        savenode[pos[0][2]]->next=savenode[pos[0][0]];//cout<<"<<<"<<pos[0][0]<<" "<<pos[0][1]<<" "<<pos[0][2]<<endl;
        for(int i=1;i<nn;i++)
        {
            savenode[pos[i][0]]=new node;
            savenode[pos[i][0]]->num=pos[i][0];//cout<<"<<<"<<pos[i][0]<<" "<<pos[i][1]<<" "<<pos[i][2]<<endl;
            if(savenode[pos[i][1]]->next->num==pos[i][2])
            {
                savenode[pos[i][1]]->next=savenode[pos[i][0]];
                savenode[pos[i][0]]->next=savenode[pos[i][2]];
            }
            else
            {
                savenode[pos[i][2]]->next=savenode[pos[i][0]];
                savenode[pos[i][0]]->next=savenode[pos[i][1]];
            }
        }
        struct node* p=savenode[1];
        for(int i=0;i<n;i++)
        {
            printf("%d%c",p->num," \n"[i==n-1]);
            p=p->next;
        }
        for(int i=0;i<nn;i++)
        {
            printf("%d%c",vis[i]," \n"[i==nn-1]);
        }
        for(int i=1;i<=n;i++)delete savenode[i];
        for(int i=0;i<=n;i++)
        {
            v[i].clear();
            visedge[i]=0;
            nn=0;
            vis[i]=0;
            num[i]=0;
        }
    }
    return 0;
}