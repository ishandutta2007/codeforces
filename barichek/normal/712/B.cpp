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

map<char,int> cnt;

main()
{
    string s;
    cin>>s;
    if (s.length()%2!=0) return cout<<-1, 0;
    for (auto i:s)
        cnt[i]++;
    int ans=maxint;
    for (int i=0;i<=s.length()/2;i++)
    {
        //cerr<<i<<" "<<ans<<endl;
        int cur=abs(cnt['U']-i)+abs(cnt['D']-i)+abs(cnt['L']-(((int)s.length()-2*i)/2))+abs(cnt['R']-(((int)s.length()-2*i)/2));
        //cerr<<cur<<endl;
        ans=min(ans,cur/2);
    }
    cout<<ans;
}