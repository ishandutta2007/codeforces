#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=2e5+100;


vector<int> vec[arr];
int color[arr],sum[arr],cnt[arr];

int get(int u)
{
    if (color[u]==u)
        return(u); else
        return(color[u]=get(color[u]));
}

signed main()
{
    int n,m;
    cin>>n>>m;
    set<int> setik;
    while (m--)
    {
        int a,b;
        cin>>a>>b;
        if (a<b)
            swap(a,b);
        vec[a].pb(b);
    }

    for (int i=1;i<=n;i++)
    {
        color[i]=i;
        sum[i]=1;
    }

    vector<int> stars;

    for (int i=1;i<=n;i++)
    {
        for (auto j:vec[i])
        {
            int now=get(j);
            cnt[now]++;
        }

        vector<int> mer;
        vector<int> new_starts;

        for (auto j:stars)
        {
            if (sum[j]>cnt[j])
                mer.pb(j); else
                new_starts.pb(j);
        }

        for (auto j:vec[i])
        {
            int now=get(j);
            cnt[now]--;
        }

        if (!mer.empty())
        {
            int now=i;

            for (auto j:mer)
            {
                int nn=j;
                if (rand()%2)
                    swap(now,nn);
                color[nn]=now;
                sum[now]+=sum[nn];
            }

            new_starts.pb(now);
            stars=new_starts;
        } else
        {
            stars.pb(i);
        }


    }

    cout<<stars.size()<<'\n';
    vector<int> ans;
    for (auto i:stars)
        ans.pb(sum[i]);

    sort(ans.begin(),ans.end());

    for (auto i:ans)
        cout<<i<<' ';
}
/*
2
set physicsexercise 2
query physicsexercise
*/