#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-10;

///---program start---///

#define int ll

map<ll,ll> cnt;

void add(int a)
{
    ll res=0;
    int cur=0;
    while (a!=0)
    {
        res+=((a%10)%2==1)*(1ll<<cur);
        cur++;
        a/=10;
    }
    cnt[res]++;
}

void del(int a)
{
    ll res=0;
    int cur=0;
    while (a!=0)
    {
        res+=((a%10)%2==1)*(1ll<<cur);
        cur++;
        a/=10;
    }
    cnt[res]--;
}

int _ans(int a)
{
    ll res=0;
    int cur=0;
    while (a!=0)
    {
        res+=((a%10)%2==1)*(1ll<<cur);
        cur++;
        a/=10;
    }
    return cnt[res];
}

main()
{
    int n;
    cin>>n;
    while (n--)
    {
        char type;
        ll zn;
        cin>>type;
        scanf("%I64d",&zn);
        if (type=='+')
            add(zn);
        elif (type=='-')
            del(zn);
        else
            cout<<_ans(zn)<<"\n";
    }
}