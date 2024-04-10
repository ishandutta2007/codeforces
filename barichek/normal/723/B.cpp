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
    string s;
    cin>>s>>s;
    int ans1=0;
    int ans2=0;
    bool in=false;
    int cur=0;
    for (int i=0;i<s.length();i++)
        if (s[i]=='(')
        {
            in=true;
            ans2=max(ans2,cur);
            cur=0;
        }
        elif (s[i]==')')
            in=false;
        elif (in)
        {
            if (i!=0&&s[i]!='_'&&(s[i-1]=='('||s[i-1]=='_')) ans1++;
        }
        else
            if (s[i]=='_')
            {
                ans2=max(ans2,cur),
                cur=0;
            }
            else cur++;
    ans2=max(ans2,cur);
    cout<<ans2<<" "<<ans1;
}