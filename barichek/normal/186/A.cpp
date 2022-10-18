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

bool use[ar];

main()
{
    string s,t;
    cin>>s>>t;
    if (s.length()!=t.length())
        return cout<<"NO", 0;
    int cnt=0;
    char a1='1';
    char b1='1';
    char a2;
    char b2;
    for (int i=0;i<s.length();i++)
    {
        cnt+=(s[i]!=t[i]);
        if (s[i]!=t[i])
        {
            if (a1=='1')
                a1=s[i];
            else
                a2=s[i];

            if (b1=='1')
                b1=t[i];
            else
                b2=t[i];
        }
    }
    if (cnt==0)
    {
        for (auto i:s)
            if (use[i]) return cout<<"YES", 0;
            else use[i]=true;
        return cout<<"NO", 0;
    }
    if (cnt!=2) return cout<<"NO", 0;
    cout<<(a1==b2&&a2==b1?"YES":"NO");
}