#include <bits/stdc++.h>

#define fin freopen("rsq.in","r",stdin)
#define fout freopen("rsq.out","w",stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sqr(x) ((x)*(x))
#define elif else if
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

#ifdef WIN32
    #define L "%I64d"
#else
    #define L "%lld"
#endif

using namespace std;

typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;
typedef long double ld;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const ll md=1e9+7;
const ld eps=1e-6;

string s;
bool ok;

void rec(int now,int skok,int ans)
{
    if (s[now]=='.') return;
    if (ans==5)
    {
        ok=true;
        return ;
    }
    if (now+skok<s.length()) rec(now+skok,skok,ans+1);
}

int main()
{
    cin>>s>>s;
    for (int i=0;i<s.length();i++)
    {
        if (ok) break;
        if (s[i]=='*')
            for (int j=1;j<s.length();j++)
                rec(i,j,1);
    }
    printf((ok)?"yes":"no");
    return 0;
}