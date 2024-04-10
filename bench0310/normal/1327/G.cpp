#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

const int K=14;

struct Vertex
{
    char c;
    int p;
    array<int,K> trie;
    array<int,K> go;
    int link;
    ll val;
    ll sum;
    Vertex(char nc='$',int np=-1):c(nc),p(np)
    {
        trie.fill(-1);
        go.fill(-1);
        link=-1;
        val=sum=0;
    }
};

vector<Vertex> ac(1);

void add(string s,ll val)
{
    int now=0;
    for(char t:s)
    {
        int c=(t-'a');
        if(ac[now].trie[c]==-1)
        {
            ac[now].trie[c]=ac.size();
            ac.push_back(Vertex(t,now));
        }
        now=ac[now].trie[c];
    }
    ac[now].val+=val;
    ac[now].sum+=val;
}

int go(int a,char t);

int get_link(int a)
{
    if(ac[a].link==-1)
    {
        if(a==0||ac[a].p==0) ac[a].link=0;
        else ac[a].link=go(get_link(ac[a].p),ac[a].c);
    }
    return ac[a].link;
}

int go(int a,char t)
{
    int c=(t-'a');
    if(ac[a].go[c]==-1)
    {
        if(ac[a].trie[c]!=-1) ac[a].go[c]=ac[a].trie[c];
        else ac[a].go[c]=(a==0?0:go(get_link(a),t));
    }
    return ac[a].go[c];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    for(int i=0;i<k;i++)
    {
        string t;
        ll val;
        cin >> t >> val;
        add(t,val);
    }
    int n=(int)ac.size()-1;
    string s;
    cin >> s;
    for(int i=1;i<=n;i++)
    {
        int now=get_link(i);
        while(now!=0)
        {
            ac[i].sum+=ac[now].val;
            now=get_link(now);
        }
    }
    const ll inf=(1ll<<60);
    vector<vector<ll>> dp(n+1,vector<ll>((1<<K),-inf));
    dp[0][0]=0;
    int l=0;
    int sz=s.size();
    auto mx=[](ll &a,ll b){a=max(a,b);};
    while(l<sz)
    {
        vector<vector<ll>> ndp(n+1,vector<ll>((1<<K),-inf));
        if(s[l]=='?')
        {
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<(1<<K);j++)
                {
                    if(dp[i][j]==-inf) continue;
                    for(int x=0;x<K;x++)
                    {
                        if(j&(1<<x)) continue;
                        int to=go(i,x+'a');
                        mx(ndp[to][j^(1<<x)],dp[i][j]+ac[to].sum);
                    }
                }
            }
            l++;
        }
        else
        {
            int r=l;
            while(r+1<sz&&isalpha(s[r+1])) r++;
            for(int i=0;i<=n;i++)
            {
                int now=i;
                ll val=0;
                for(int j=l;j<=r;j++)
                {
                    now=go(now,s[j]);
                    val+=ac[now].sum;
                }
                for(int j=0;j<(1<<K);j++) if(dp[i][j]!=-inf) mx(ndp[now][j],dp[i][j]+val);
            }
            l=r+1;
        }
        dp=move(ndp);
    }
    ll res=-inf;
    for(int i=0;i<=n;i++) for(int j=0;j<(1<<K);j++) mx(res,dp[i][j]);
    cout << res << "\n";
    return 0;
}