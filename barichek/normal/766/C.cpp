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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

/// sydoran is our lord
/// melnyk is our krevedka
/// oryshych is our kaban
/// mitsa is our batya
/// kek is our cheburek
/// oros is our down
/// goban is our huyoban
/// pechora is our maksim
/// arsijo is our tasher
/// filip is our petuh
/// vetal is our vseukr

void inc(int &a,int b,int md=md)
{
    a+=b;
    a%=md;
    a+=md;
    a%=md;
}

int dp[arr];
int dp1[arr];
vi cnt;
int n;
string s;
int ans1;
int ans2;
int ans3;

bool can(int l,int r,vector<char> &use)
{
    for (int i=0;i<26;i++)
        if (use[i]&&r-l+1>cnt[i])
            return false;
    return void(ans2=max(ans2,r-l+1)), true;
}

main()
{
    fast;
    cin>>s>>s;
    cnt.clear();
    cnt.resize(26);
    for (auto &i:cnt)
        cin>>i;
    dp[0]=1;
    for (int i=0;i<s.length();i++)
    {
        vector<char> use(26,false);
        for (int j=i+1;j<=s.length();j++)
        {
            use[s[j-1]-'a']=true;
            if (can(i,j-1,use))
                inc(dp[j],dp[i]);
        }
    }
    dp1[0]=1;
    for (int i=1;i<arr;i++)
        dp1[i]=1e10;
    for (int i=0;i<s.length();i++)
    {
        vector<char> use(26,false);
        for (int j=i+1;j<=s.length();j++)
        {
            use[s[j-1]-'a']=true;
            if (can(i,j-1,use))
                dp1[j]=min(dp1[j],dp1[i]+1);
        }
    }
    ans1=dp[s.length()];
    ans3=dp1[s.length()];
    cout<<ans1<<"\n";
    cout<<ans2<<"\n";
    cout<<ans3-1<<"\n";
}