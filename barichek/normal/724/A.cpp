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

vi a={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string s,t;
    map<string,int> vh;
bool solve(int x)
{
    int now=vh[s];
    for (int i=0;i<a[x];i++)
        now++;
    now%=7;
    //cout<<now<<" !!\n";
    if (vh[t]==now) return true;
    return false;
}

main()
{
    vh["monday"]=0;
    vh["tuesday"]=1;
    vh["wednesday"]=2;
    vh["thursday"]=3;
    vh["friday"]=4;
    vh["saturday"]=5;
    vh["sunday"]=6;
    cin>>s>>t;
    for (int i=0;i<11;i++)
        if (solve(i)) return cout<<"YES", 0;
    cout<<"NO";
}