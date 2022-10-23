#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e6+10,mod=1e9+7,inf=1e18;

struct ds
{
    int sta,len,color;
};

int a[maxn],n,mark[maxn],sl=1;
ds interval[maxn];
void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}

set<pii> s;
priority_queue<pii> q;

void build()
{
    int st=1,len=1;
    for (int i=2;i<=n;i++)
        if (a[i]==a[i-1]) len++;
        else
        {
            s.insert(mp(st,sl));
            q.push(mp(len,n-st));
            interval[sl++]={st,len,a[i-1]};
            st=i;
            len=1;
        }
    s.insert(mp(st,sl));
    q.push(mp(len,n-st));
    interval[sl++]={st,len,a[n]};
}

void process()
{
    int res=0;
    while (s.size())
    {
        res++;
        int l=n-q.top().se;
        auto it=s.lower_bound(mp(l,0));
        auto it2=it;
        it2++;
        if (it!=s.begin() && it2!=s.end())
        {
            auto it1=it;
            it1--;
            pii tmp1=*it1,tmp2=*it2;
            int id1=tmp1.se,id2=tmp2.se;
            if (interval[id1].color==interval[id2].color)
            {
                int sta=tmp1.fi,len=interval[id1].len+interval[id2].len;
                s.erase(it1);
                it=s.lower_bound(mp(l,0));
                it2=it;
                it2++;
                s.erase(it2);
                mark[tmp2.fi]=1;
                s.insert(mp(sta,sl));
                q.push(mp(len,n-sta));
                interval[sl++]={sta,len,interval[id1].color};
                it=s.lower_bound(mp(l,0));
            }
        }
        s.erase(it);
        mark[l]=1;
        while (!q.empty() && mark[n-q.top().se]) q.pop();
    }
    cout<<res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    build();
    process();
    return 0;
}