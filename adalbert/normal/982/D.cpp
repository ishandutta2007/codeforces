#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#pragma GCC optimize ("O2")
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int,int> cnt;

void add(int u, int z)
{
    if (u==0)
    exit(1);
    cnt[u]+=z;
    if (cnt[u]==0)
        cnt.erase(u);
}
int a[200000];

signed main()
{
    int n;
    cin>>n;

    map<int,vector<int> > mp;
    set<pair<int,int> > setik;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[-a[i]].pb(i);
    }
    sort(a+1,a+1+n);

    setik.insert(m_p(1,n));
    cnt[n]++;

    int ans=1;
    int ians=a[n]+1;

    for (auto i:mp)
    {
        for (auto j:i.sec)
        {
            auto now=setik.lower_bound(m_p(j,j));
            while (now!=setik.begin())
            {
                auto pred=now;
                pred--;
                if (pred->sec>=j)
                    now--; else break;
            }
            while (1)
            {
                auto pred=now;
                pred++;
                if (pred==setik.end())
                    break;
                if (pred->fir<=j)
                    now++; else break;

            }
            pair<int,int> tutu=*now;

            pair<int,int> left={tutu.fir,j-1};
            pair<int,int> right={j+1,tutu.sec};

            add(tutu.sec-tutu.fir+1,-1);
            setik.erase(tutu);
            if (left.fir<=left.sec)
            {
                setik.insert(left);
                add(left.sec-left.fir+1,1);
            }
            if (right.fir<=right.sec)
            {
                setik.insert(right);
                add(right.sec-right.fir+1,1);
            }
        }

        if (i.fir==-45567032)
            return(0);

        if (cnt.size()<=1)
        {
            if (setik.size()>=ans)
            {
                ans=setik.size();
                ians=-i.fir;
            }
        }

    }

    int mx=0;

    for (int i=1;i<=n;i++)
        if (a[i]<ians)
        mx=max(mx,a[i]);

    cout<<mx+1;
}
/*
18
1 6 11 2 7 12 3 8 13 4 9 14 5 10 15 0 -1 -2
*/