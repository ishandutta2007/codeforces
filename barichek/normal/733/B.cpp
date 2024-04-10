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

main()
{
    int n;
    cin>>n;
    vector<pii> a;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin>>a[i].fir>>a[i].sec;
    int sum_l=0;
    int sum_r=0;
    int res=-1;
    for (auto i:a)
        sum_l+=i.fir,
        sum_r+=i.sec;
    int mx=abs(sum_l-sum_r);
    for (int i=0;i<n;i++)
    {
        int cur_l=sum_l;
        int cur_r=sum_r;
        cur_l-=a[i].fir;
        cur_l+=a[i].sec;
        cur_r-=a[i].sec;
        cur_r+=a[i].fir;
        if (abs(cur_l-cur_r)>mx)
            mx=abs(cur_l-cur_r),
            res=i;
    }
    cout<<res+1;
}