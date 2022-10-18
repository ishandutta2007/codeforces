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

main()
{
    /*
    int s,x1,x2;
    cin>>s>>x1>>x2;
    int t1,t2;
    cin>>t1>>t2;
    int p,d;
    cin>>p>>d;
    int cur_time=0;
    int cur_train=p;
    int cur_ihor=x1;
    int cur_d=d;
    while (cur_time++)
    {
        if (cur_train==cur_ihor&&cur_d==(x2>1))
    }
    */
    int n,m;
    cin>>n>>m;
    vi a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    map<int,int> use;
    use.clear();
    for (auto &i:a)
        if (use[i])
            i=-1;
        else
            use[i]=true;
    int cnt_all_0=m/2;
    int cnt_all_1=m/2+m%2;
    for (auto i:a)
        if (i>m)
        {
            if (i%2==0)
                cnt_all_0++;
            else
                cnt_all_1++;
        }
    if (cnt_all_0<n/2||cnt_all_1<n/2) return cout<<-1, 0;
    int ans=0;
    int last_0=2;
    int last_1=1;
    while (use[last_0])
        last_0+=2;
    while (use[last_1])
        last_1+=2;
    int cnt_0=0;
    int cnt_1=0;
    for (auto i:a)
        if (i!=-1)
        {
            if (i%2==0)
                cnt_0++;
            else
                cnt_1++;
        }
    for (auto &i:a)
        if (i==-1)
        {
            ans++;
            if (cnt_0<cnt_1)
            {
                i=last_0;
                last_0+=2;
                while (use[last_0])
                    last_0+=2;
                cnt_0++;
            }
            else
            {
                i=last_1;
                last_1+=2;
                while (use[last_1])
                    last_1+=2;
                cnt_1++;
            }
        }
    for (auto &i:a)
        if (cnt_0!=cnt_1)
        {
            if (cnt_0<cnt_1&&i%2==1)
            {
                ans++;
                i=last_0;
                last_0+=2;
                while (use[last_0])
                    last_0+=2;
                cnt_0++;
                cnt_1--;
            }
            elif (cnt_0>cnt_1&&i%2==0)
            {
                ans++;
                i=last_1;
                last_1+=2;
                while (use[last_1])
                    last_1+=2;
                cnt_1++;
                cnt_0--;
            }
        }
    cout<<ans<<"\n";
    for (auto i:a)
        cout<<i<<" ";
}