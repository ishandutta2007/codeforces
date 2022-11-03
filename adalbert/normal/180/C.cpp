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

int pref[arr];
int suf[arr];

main()
{
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++)
        pref[i]=i>0?pref[i-1]+(tolower(s[i])==s[i]):(tolower(s[i])==s[i]);
    for (int i=s.length()-1;i>=0;i--)
        suf[i]=suf[i+1]+(tolower(s[i])!=s[i]);
    int ans=maxint;
    for (int i=0;i<s.length();i++)
        //cout<<i<<" "<<(i>0?pref[i-1]:0)+suf[i+1]<<"\n",
        ans=min(ans,(i>0?pref[i-1]:0)+suf[i+1]);
    cout<<ans;
}