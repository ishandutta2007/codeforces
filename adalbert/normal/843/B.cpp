#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <pii> vii;
const ld pi = acos(-1);
const int arr = 4*1e5+100;
const ll md = 1e9+7;
const ll base=31;
const int AaA = 'a'-'A';
ld eps=1e-7;
int cnt=1000;

map<int,pair<int,int> > mp;

pair<int,int> ask(int u)
{
    if (mp.count(u))
    {
        return(mp[u]);
    }
    cnt--;
    cout<<'?'<<' '<<u<<'\n';
    fflush(stdout);
    int a,b;
    cin>>a>>b;
    if (a==-1) exit(1);
    mp[u]={a,b};
    return(make_pair(a,b));
}

signed main()
{
    srand(time(0));
    int start,n,x;
    cin>>n>>start>>x;
    int imn=start;
    int mn=ask(start).fir;
    vector<int> can;
    for (int i=1;i<=n;i++)
        if (i!=start)
        can.pb(i);

    random_shuffle(can.begin(),can.end());
    for (int i=1;i<=min(n-1,cnt);i++)
    {
        int to=can[i-1];

        pair<int,int> now=ask(to);
        if (now.fir==mn)
            exit(1);
        if (now.fir<x && now.fir>mn)
        {
            mn=now.fir;
            imn=to;
        }
    }

    start=imn;
    while (start!=-1)
    {
        pair<int,int> now=ask(start);
        if (now.fir>=x)
        {
            cout<<'!'<<' '<<now.fir<<'\n';
            fflush(stdout);
            return(0);
        }
        start=now.sec;
    }
    cout<<'!'<<' '<<-1<<'\n';
    fflush(stdout);

}