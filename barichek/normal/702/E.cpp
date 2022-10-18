#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

struct stb_
{
    int pred[50];
    ll sum[50];
    int minim[50];
} stb[arr];

int _log;
ll n,len;
ll step2[50];
int where[arr],cost[arr];
pair<ll,ll> all_res[arr];

void __stb()
{
    _log=log2(len);
    for (int i=0;i<=_log;i++)
        for (int j=0;j<n;j++)
            stb[j].pred[i]=i?stb[stb[j].pred[i-1]].pred[i-1]:where[j],
            stb[j].sum[i]=i?stb[j].sum[i-1]+stb[stb[j].pred[i-1]].sum[i-1]:cost[j],
            stb[j].minim[i]=i?min(stb[j].minim[i-1],stb[stb[j].pred[i-1]].minim[i-1]):cost[j];
}

pair<ll,ll> _ans(int start)
{
    ll ans1=0;
    int ans2=maxint;
    ll len_=len;
    int now=start;
    for (ll i=_log;i>=0;i--)
    {
        if (len_>=step2[i])
        {
            len_-=step2[i];
            ans1+=stb[now].sum[i];
            ans2=min(ans2,stb[now].minim[i]);
            now=stb[now].pred[i];
        }
    }
    return mp(ans1,ans2);
}

void __step2()
{
    for (int i=0;i<50;i++)
        step2[i]=i?step2[i-1]*2:1;
}

void _debug()
{
    for (int i=0;i<n;i++)
    {
        cout<<"!!! "<<i<<" !!!\n";
        for (int j=0;j<n;j++)
            cout<<"stb["<<i<<"].pred["<<j<<"]=="<<stb[i].pred[j]<<"\n",
            cout<<"stb["<<i<<"].sum["<<j<<"]=="<<stb[i].sum[j]<<"\n",
            cout<<"stb["<<i<<"].minim["<<j<<"]=="<<stb[i].minim[j]<<"\n";
    }
}

int main()
{
    cin>>n>>len;
    for (int i=0;i<n;i++)
        cin>>where[i];
    for (int i=0;i<n;i++)
        cin>>cost[i];
    __step2();
    __stb();
    //_debug();
    for (int i=0;i<n;i++)
        all_res[i]=_ans(i);
    for (int i=0;i<n;i++)
        cout<<all_res[i].fir<<" "<<all_res[i].sec<<"\n";
}