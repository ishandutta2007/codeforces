#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
int mark[3*maxn];
struct node
{
    int sl;
    node *bit[2];
    node()
    {
        bit[0] = bit[1] = NULL;
        sl = 0;
    }
};

node *root;

void add(int x)
{
    node *cur=root;
    for (int i=19;i>=0;i--)
    {
        if (cur->bit[(x>>i) & 1] == NULL) cur->bit[(x>>i) & 1] = new node();
        cur=cur->bit[(x>>i) & 1];
        (cur->sl)++;
    }
}

int findv(int x)
{
    node *cur=root;
    int ans=0;
    for (int i=19;i>=0;i--)
        if (cur->bit[(x>>i) & 1]==NULL) return ans;
        else if ((cur->bit[(x>>i) & 1])->sl<(1<<i)) cur=cur->bit[(x>>i) & 1];
        else
        {
            ans+=1<<i;
            if (cur->bit[((x>>i) & 1)^1]==NULL) return ans;
            cur=cur->bit[((x>>i) & 1)^1];
        }
    return ans;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    root = new node();
    int n,m,x,t=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if (!mark[x])
        {
            add(x);
            mark[x]=1;
        }
    }
    for (int i=1;i<=m;i++) scanf("%d",&x),t^=x,printf("%d\n",findv(t));
    return 0;
}