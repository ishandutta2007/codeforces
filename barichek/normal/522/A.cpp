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

string ukaz;
int n,res;
map<string,int> ans;

int main()
{
    cin>>n;
    ans["POLYCARP"]=1;
    for (int j=0;j<n;j++)
    {
        string s1,s2;
        cin>>s1>>s2>>s2;
        for (int i=0;i<s1.length();i++)
            s1[i]=toupper(s1[i]);
        for (int i=0;i<s2.length();i++)
            s2[i]=toupper(s2[i]);
        ans[s1]=ans[s2]+1;
        //cout<<s1<<" "<<s2<<"\n";
        if (ans[ukaz]<ans[s1]) ukaz=s1;
    }
    cout<<ans[ukaz];
    return 0;
}