#include <bits/stdc++.h>

#define fin freopen("input.txt","r",stdin)
#define fout freopen("output.txt","w",stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sqr(x) (x)*(x)
#define elif else if
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define L "%lld"
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;
typedef long double ld;

const ull maxull=18446744073709551615;
const ll maxll=9223372036854775807;
const int maxint=2147483647;
const ll md=1e9+7;
const ld eps=1e-6;

int n,ans;
string s;
map<char,int> cnt;

int main()
{
    //fast;
    cin>>n;
    if (n>26) return cout<<-1, 0;
    cin>>s;
    //cout<<s;
    for (int i=0;i<s.length();i++)
        cnt[s[i]]++;
    for (char i='a';i<='z';i++)
        ans+=max(0,cnt[i]-1);
    cout<<ans;
    return 0;
}