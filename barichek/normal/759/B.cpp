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

int dp[arr];
int a[arr];

void minimize(int &a,int b)
{
    if (a>b) a=b;
}

void erase(multiset<int> &a,int b)
{
    auto it=a.find(b);
    if (it==a.end()) return;
    //cout<<"real erase !!!\n";
    a.erase(it);
}

main()
{
    fill(dp,dp+arr,1e15);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int p1=1;
    multiset<int> dp1;
    int p2=1;
    multiset<int> dp2;
    dp[0]=0;
    dp1.insert(0);
    dp2.insert(0);
    a[0]=a[1];
    for (int i=1;i<=n;i++)
    {
        //cout<<"before :: "<<p1<<" "<<p2<<"\n";
        dp[i]=(i==0?0:dp[i-1])+20;
        while (a[i]-90>=a[p1])
            erase(dp1,dp[p1++-1]);
        while (a[i]-1440>=a[p2])
            erase(dp2,dp[p2++-1]);
        /*
        cout<<i<<" ------\n";
        cout<<"dp1 ::\n";
        for (auto i:dp1)
            cout<<i<<" ";
        cout<<"\n";
        cout<<"dp2 ::\n";
        for (auto i:dp2)
            cout<<i<<" ";
        cout<<"\n";
        */
        if (!dp1.empty())
            minimize(dp[i],*dp1.begin()+50);
        if (!dp2.empty())
            minimize(dp[i],*dp2.begin()+120);
        dp1.insert(dp[i]);
        dp2.insert(dp[i]);
        //cout<<i<<" :: "<<dp[i]<<"\n";
    }
    int cur=0;
    for (int i=1;i<=n;i++)
    {
        cout<<min(cur+20,dp[i])-cur<<"\n";
        cur=min(cur+20,dp[i]);
        //cout<<cur<<"\n";
    }
}