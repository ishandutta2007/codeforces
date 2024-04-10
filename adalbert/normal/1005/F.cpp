#include <bits/stdc++.h>

using namespace std;

#define fir first
#define sec second
#define pb push_back
#define int ll

typedef long long ll;

int a[300000],b[300000],last[300000],len[300000],use[300000];
vector<int> vec[300000],bac[300000];
signed main()
{
    int n,m,k;
    cin>>n>>m>>k;

    for (int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];

        vec[a[i]].pb(b[i]);
        vec[b[i]].pb(a[i]);
    }

    queue<int> q;

    q.push(1);

    len[1]=0;

    for (int i=2;i<=n;i++)
        len[i]=1e9;

    while (!q.empty())
    {
        int now=q.front();
        q.pop();

        for (auto i:vec[now])
            if (len[i]>len[now]+1)
            {
                len[i]=len[now]+1;
                q.push(i);
            }
    }

    for (int i=1;i<=m;i++)
    {
        if (len[a[i]]==len[b[i]]-1)
            bac[b[i]].pb(i);
        if (len[b[i]]==len[a[i]]-1)
            bac[a[i]].pb(i);
    }

    for (int i=1;i<=n;i++)
        last[i]=0;

    vector<string> tutu;

    while (k--)
    {
        int cnt=0;
        for (int i=2;i<=n;i++)
        {
            use[bac[i][last[i]]]=1;
            if (last[i]==bac[i].size()-1)
            cnt++;
        }
        string now="";
        for (int i=1;i<=m;i++)
        {
            now+=use[i]+'0';
            use[i]=0;
        }
        tutu.pb(now);
        if (cnt==n-1)
            break;
        int endd=n;
        while (bac[endd].size()-1==last[endd])
        {
            last[endd]=0;
            endd--;
        }
        last[endd]++;
    }

    cout<<tutu.size()<<'\n';
    for (auto i:tutu)
        cout<<i<<'\n';
}