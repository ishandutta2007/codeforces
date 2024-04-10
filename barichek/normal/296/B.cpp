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
const ld eps=1e-6;

///---program start---///

ll dp[arr][2][2];

main()
{
    string s,t;
    cin>>t>>s>>t;
    s="#"+s;
    t="#"+t;
    dp[0][false][false]=1;
    for (int i=1;i<s.length();i++)
    {
        if (s[i]!='?'&&t[i]!='?')
        {
            if (s[i]>t[i])
            {
                dp[i][true][true]=(dp[i][true][true]+dp[i-1][false][true]+dp[i-1][true][true]+md)%md;
                dp[i][true][false]=(dp[i][true][false]+dp[i-1][false][false]+dp[i-1][true][false]+md)%md;
            }
            elif (s[i]<t[i])
            {
                dp[i][true][true]=(dp[i][true][true]+dp[i-1][true][false]+dp[i-1][true][true]+md)%md;
                dp[i][false][true]=(dp[i][false][true]+dp[i-1][false][false]+dp[i-1][false][true]+md)%md;
            }
            else
            {
                    dp[i][true][true]=(dp[i][true][true]+dp[i-1][true][true]+md)%md;
                    dp[i][true][false]=(dp[i][true][false]+dp[i-1][true][false]+md)%md;
                    dp[i][false][false]=(dp[i][false][false]+dp[i-1][false][false]+md)%md;
                    dp[i][false][true]=(dp[i][false][true]+dp[i-1][false][true]+md)%md;
            }
        }
        elif (s[i]=='?'&&t[i]=='?')
        {
            for (char s1='0';s1<='9';s1++)
                for (char s2='0';s2<='9';s2++)
                    if (s1>s2)
                    {
                        dp[i][true][true]=(dp[i][true][true]+dp[i-1][false][true]+dp[i-1][true][true]+md)%md;
                        dp[i][true][false]=(dp[i][true][false]+dp[i-1][false][false]+dp[i-1][true][false]+md)%md;
                    }
                    elif (s1<s2)
                    {
                        dp[i][true][true]=(dp[i][true][true]+dp[i-1][true][false]+dp[i-1][true][true]+md)%md;
                        dp[i][false][true]=(dp[i][false][true]+dp[i-1][false][false]+dp[i-1][false][true]+md)%md;
                    }
                    else
                    {
                        dp[i][true][true]=(dp[i][true][true]+dp[i-1][true][true]+md)%md;
                        dp[i][true][false]=(dp[i][true][false]+dp[i-1][true][false]+md)%md;
                        dp[i][false][false]=(dp[i][false][false]+dp[i-1][false][false]+md)%md;
                        dp[i][false][true]=(dp[i][false][true]+dp[i-1][false][true]+md)%md;
                    }
        }
        elif (s[i]=='?')
        {
            for (char s1='0';s1<='9';s1++)
                if (s1>t[i])
                {
                    dp[i][true][true]=(dp[i][true][true]+dp[i-1][false][true]+dp[i-1][true][true]+md)%md;
                    dp[i][true][false]=(dp[i][true][false]+dp[i-1][false][false]+dp[i-1][true][false]+md)%md;
                }
                elif (s1<t[i])
                {
                    dp[i][true][true]=(dp[i][true][true]+dp[i-1][true][false]+dp[i-1][true][true]+md)%md;
                    dp[i][false][true]=(dp[i][false][true]+dp[i-1][false][false]+dp[i-1][false][true]+md)%md;
                }
                else
                {
                    dp[i][true][true]=(dp[i][true][true]+dp[i-1][true][true]+md)%md;
                    dp[i][true][false]=(dp[i][true][false]+dp[i-1][true][false]+md)%md;
                    dp[i][false][false]=(dp[i][false][false]+dp[i-1][false][false]+md)%md;
                    dp[i][false][true]=(dp[i][false][true]+dp[i-1][false][true]+md)%md;
                }
        }
        else
        {
            for (char s2='0';s2<='9';s2++)
                if (s[i]>s2)
                {
                    dp[i][true][true]=(dp[i][true][true]+dp[i-1][false][true]+dp[i-1][true][true]+md)%md;
                    dp[i][true][false]=(dp[i][true][false]+dp[i-1][false][false]+dp[i-1][true][false]+md)%md;
                }
                elif (s[i]<s2)
                {
                    dp[i][true][true]=(dp[i][true][true]+dp[i-1][true][false]+dp[i-1][true][true]+md)%md;
                    dp[i][false][true]=(dp[i][false][true]+dp[i-1][false][false]+dp[i-1][false][true]+md)%md;
                }
                else
                {
                    dp[i][true][true]=(dp[i][true][true]+dp[i-1][true][true]+md)%md;
                    dp[i][true][false]=(dp[i][true][false]+dp[i-1][true][false]+md)%md;
                    dp[i][false][false]=(dp[i][false][false]+dp[i-1][false][false]+md)%md;
                    dp[i][false][true]=(dp[i][false][true]+dp[i-1][false][true]+md)%md;
                }

        }
    }
    cout<<dp[s.length()-1][true][true];
}