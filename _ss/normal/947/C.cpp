#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=3e5+10,msiz=2,mod=1e9+7,inf=1e18;

struct node
{
    int left,right,sl;
};
vector<node> trie;

void build()
{
    //for (int i=0;i<30;i++) trie.pb({i+1,-1,1});
    //trie.pb({-1,-1,1});
    trie.pb({-1,-1,0});
}

void add(int x)
{
    int t=0;
    for (int i=29;i>=0;i--)
        if (x & (1<<i))
        {
            if (trie[t].right==-1)
            {
                trie.pb({-1,-1,0});
                trie[t].right=trie.size()-1;
            }
            trie[t].sl++;
            t=trie[t].right;
        }
        else
        {
            if (trie[t].left==-1)
            {
                trie.pb({-1,-1,0});
                trie[t].left=trie.size()-1;
            }
            trie[t].sl++;
            t=trie[t].left;
        }
    trie[t].sl++;
}

void del(int x)
{
    int t=0;
    for (int i=29;i>=0;i--)
        if (x & (1<<i)) trie[t].sl--,t=trie[t].right;
        else trie[t].sl--,t=trie[t].left;
    trie[t].sl--;
}

int findx(int x)
{
    int t=0,ans=0;
    for (int i=29;i>=0;i--)
        if (x & (1<<i))
        {
            if (trie[t].right!=-1 && trie[trie[t].right].sl) ans+=(1<<i),t=trie[t].right;
            else t=trie[t].left;
        }
        else
        {
            if (trie[t].left!=-1 && trie[trie[t].left].sl) t=trie[t].left;
            else t=trie[t].right,ans+=(1<<i);
        }
    return ans;
}

 int a[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n;
    build();
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>x,add(x);
    for (int i=1;i<=n;i++)
    {
        int tmp=findx(a[i]);
        del(tmp);
        cout<<(tmp^a[i])<<" ";
    }
    return 0;
}