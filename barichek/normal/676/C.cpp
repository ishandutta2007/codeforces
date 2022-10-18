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

int n,k;
string s;

bool check(int key)
{
    //cout<<key<<"\n";
    int ka=0,kb=0;
    for (int i=0;i<key;i++)
        if (s[i]=='a') ka++;
        else kb++;
    for (int i=key;i<s.length();i++)
    {
        if (kb<=k||ka<=k)
        {
            //cout<<i<<"\n\n";
            return true;
        }
        if (s[i-key]=='a') ka--;
        else kb--;
        if (s[i]=='a') ka++;
        else kb++;
    }
    if (kb<=k||ka<=k) return true; else return false;
}

void work()
{
    for (int i=0;i<=s.length()-80;i++)
    {
        int ka=0,kb=0;
        for (int j=i;j<i+80;j++)
            if (s[j]=='a') ka++;
                else kb++;
        if (ka<=k||kb<=k)
        {
            cout<<i<<" "<<i+79;
            return;
        }
    }
}

int main()
{
    cin>>n>>k;
    cin>>s;
    //work();
    //return 0;
    int l=1,r=n;
    while(r-l>1)
    {

        if (check((l+r)/2)) l=(l+r)/2; else r=(l+r)/2;
        //cout<<l<<" "<<(l+r)/2<<" "<<r<<"\n";
    }
    if (check(r)) cout<<r; else cout<<l;
    return 0;

}

/*
100 25
babbbaaababaaabbbaabaabaabbbabbabbbbaaaaaaabaaabaaaaaaaaaabaaaabaaabbbaaabaaababaaabaabbbbaaaaaaaaaa
*/