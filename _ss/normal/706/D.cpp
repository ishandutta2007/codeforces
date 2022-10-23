#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

struct node
{
    int sl;
    node *bit[2];
    node()
    {
        bit[0]=bit[1]=NULL;
        sl=0;
    }
};

node *root;

void add(int x)
{
    node *t=root;
    for (int i=30;i+1;i--)
    {
        if (t -> bit[(x>>i) & 1]==NULL) t -> bit[(x>>i) & 1]= new node();
        t = t -> bit[(x>>i) & 1];
        (t -> sl)++;
    }
}

void del(int x)
{
    node *t=root;
    for (int i=30;i+1;i--)
    {
        ((t -> bit[(x>>i) & 1]) -> sl)--;
        if ((t -> bit[(x>>i) & 1]) -> sl ==0)
        {
            t -> bit[(x>>i) & 1]=NULL;
            return;
        }
        t=t -> bit[(x>>i) & 1];
    }
}

int findx(int x)
{
    node *t=root;
    int res=0;
    for (int i=30;i+1;i--)
    {
        if (t->bit[((x>>i) & 1) ^ 1]!=NULL)
        {
            res+=1<<i;
            t=t->bit[((x>>i) & 1) ^ 1];
        }
        else t=t->bit[(x>>i) & 1];
    }
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    root = new node();
    add(0);
    int q,x;
    cin>>q;
    char c;
    for (int i=1;i<=q;i++)
    {
        cin>>c>>x;
        if (c=='+') add(x);
        else if (c=='-') del(x);
        else cout<<findx(x)<<endl;
    }
    return 0;
}