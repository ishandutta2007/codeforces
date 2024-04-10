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
///#define int long long

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

int dp[76][1ll<<20];

void inc(int &a,int b,int md=md)
{
    a+=b;
    if (a>md)
        a-=md;
}

#define next oryshych_kaban

int next[ar];

main()
{
    string s;
    cin>>s>>s;
    int last=s.length();
    for (int i=s.length()-1;i>=0;i--)
        last=(s[i]=='1'?i:last),
        next[i]=last;
    for (int i=0;i<s.length();i++)
        dp[i][0]=1;
    for (int i=0;i<s.length();i++)
    {
        if (next[i]==s.length()) continue;
        for (int old_mask=0;old_mask<(1ll<<20);old_mask++)
        {
            int cur=s[next[i]]=='1';
            for (int j=next[i];j<s.length()&&cur<=20;j++)
            {
                if (cur!=0)
                {
                    //if (dp[i][old_mask])
                      //  cout<<"inc dp["<<j+1<<"]["<<(old_mask|(1ll<<(cur-1)))<<"] from dp["<<i<<"]["<<old_mask<<"]("<<dp[i][old_mask]<<") with cur=="<<cur<<"\n";
                    inc(dp[j+1][old_mask|(1ll<<(cur-1))],dp[i][old_mask]);
                }
                cur<<=1;
                if (j+1<s.length())
                    if (s[j+1]=='1')
                        cur++;
            }
        }
    }
    for (int i=0;false&&i<=s.length();i++)
    {
        for (int mask=0;mask<4;mask++)
            cout<<"dp with i=="<<i<<" && mask=="<<mask<<" :: "<<dp[i][mask]<<"\n";
        cout<<"\n";
    }
    int ans=0;
    for (int i=0;i<=s.length();i++)
        for (int j=1;j<=20;j++)
        {
            //if (dp[i][(1ll<<j)-1])
              //  cout<<"ans+="<<"dp["<<i<<"]["<<(1ll<<j)-1<<"]("<<dp[i][(1ll<<j)-1]<<")\n";
            inc(ans,dp[i][(1ll<<j)-1]);
        }
    cout<<ans;
}