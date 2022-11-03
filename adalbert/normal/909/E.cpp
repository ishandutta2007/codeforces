#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
typedef long long ll;
typedef double ld;
const int arr=2e5+1000;

set<pair<int,int> > setik;

int cnt[arr],type[arr];
vector<int> vec[arr];

void dodo(int u)
{
    //cout<<u<<'\n';
    for (auto i:vec[u])
    {
        cnt[i]--;
        if (cnt[i]==0)
        setik.insert({type[i],i});
    }
}

signed main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>type[i];
    }

    for (int i=1;i<=m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;

        t1++;
        t2++;
        vec[t2].pb(t1);
        cnt[t1]++;
    }

    for (int i=1;i<=n;i++)
        if (cnt[i]==0)
            setik.insert({type[i],i});

    int ans=0;
    int last=0;
    while (!setik.empty())
    {
        if (last==0)
        {
            pair<int,int> now=*setik.begin();
            if (now.fir==0)
            {
                setik.erase(now);
                dodo(now.sec);
            } else
            {
                ans++;
                last=1;
            }
        } else
        {
            pair<int,int> now=*setik.rbegin();
            if (now.fir==1)
            {
                setik.erase(now);
                dodo(now.sec);
            } else
            {
                last=0;
            }
        }
    }

    cout<<ans;
}