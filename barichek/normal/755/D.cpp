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
#define int long long

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
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int ft[10*arr];

void upd(int pos,int val)
{
    //cout<<"to pos=="<<pos<<" :: "<<val<<"\n";
    for (int i=pos;i<10*arr;i|=i+1)
        ft[i]+=val;
}

int get(int pos)
{
    int res=0;
    for (int i=pos;i>=0;i&=i+1,i--)
        res+=ft[i];
    return res;
}

int get(int l,int r)
{
    //cout<<"get from :: "<<l<<" "<<r<<"\n";
    if (l>r) return 0;
    return get(r)-get(l-1);
}

main()
{
    int n,k;
    cin>>n>>k;
    k=min(k,n-k);
    int cur=1;
    int ans=1;
    for (int i=0;i<n;i++)
    {
        int to=cur+k;
        if (to>n)
            to-=n;
        int where=to;
        if (to<cur)
            ans+=get(cur+1,n)+get(1,to-1)+1;
        else
            ans+=get(cur+1,to-1)+1;
        upd(cur,+1);
        upd(to,+1);
        cur=where;
        cout<<ans<<" ";
    }
}