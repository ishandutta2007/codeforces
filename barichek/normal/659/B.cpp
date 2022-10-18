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

int n,m;
vector< pair<int,string> > vec[100001];

int main()
{
    scanf(II,&n,&m);
    for (int i=0;i<n;i++)
    {
        string s;
        int zn1,zn2;
        cin>>s>>zn1>>zn2;
        vec[zn1].pb(mp(zn2,s));
    }
    for (int i=1;i<=m;i++)
        sort(vec[i].begin(),vec[i].end());
    for (int i=1;i<=m;i++)
    {
        //cout<<i<<" "<<vec[i].size()<<"\n";
        if (vec[i].size()==2) cout<<vec[i][0].sec<<" "<<vec[i][1].sec<<"\n";
        elif (vec[i][vec[i].size()-2].fir==vec[i][vec[i].size()-3].fir) cout<<"?\n";
        else cout<<vec[i][vec[i].size()-1].sec<<" "<<vec[i][vec[i].size()-2].sec<<"\n";
    }
    return 0;
}