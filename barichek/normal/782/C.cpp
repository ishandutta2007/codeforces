#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define files_ds(name) freopen(name".dat","r",stdin); freopen(name".sol","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

vi reb[arr];
int c[arr];
int pred[arr];

void pointing(int& p,set<int> &gavno)
{
    if (gavno.count(p))
    {
        p++;
        pointing(p,gavno);
    }
}

void dfs(int now=1,int pred__=-1)
{
    pred[now]=pred__;
    int p=1;
    set<int> gavno;
    gavno.clear();
    int cur=now;
    if (cur!=-1)
        gavno.insert(c[cur]),
        cur=pred[cur];
    if (cur!=-1)
        gavno.insert(c[cur]),
        cur=pred[cur];
    for (auto wh:reb[now])
        if (wh!=pred__)
        {
            pointing(p,gavno);
            c[wh]=p;
            gavno.insert(c[wh]);
            dfs(wh,now);
        }
}

main()
{
    fast;
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    c[1]=1;
    dfs();
    set<int> color;
    color.clear();
    for (int i=1;i<=n;i++)
        color.insert(c[i]);
    cout<<color.size()<<"\n";
    for (int i=1;i<=n;i++)
        cout<<c[i]<<" ";
    cout<<"\n";
}