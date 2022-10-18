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

int cnt[ar];

main()
{
    int k;
    string s;
    cin>>k>>s;
    if (s.length()%k!=0) return cout<<-1, 0;
    for (auto i:s)
        cnt[i]++;
    string res="";
    for (char i='a';i<='z';i++)
    {
        if (cnt[i]%k!=0) return cout<<-1, 0;
        for (int j=0;j<cnt[i]/k;j++)
            res+=i;
    }
    string ans="";
    for (int i=0;i<k;i++)
        ans+=res;
    cout<<ans;
}