#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

bool want[250];
int can[250];

int n;
string s;

bool check()
{
    for (char i='a';i<='z';i++)
        if (want[i]&&!can[i]) return false;
    for (char i='A';i<='Z';i++)
        if (want[i]&&!can[i]) return false;
    return true;
}

bool check(int x)
{
    memset(can,0,sizeof(can));
    int l=0,r=x-1;
    for (int i=0;i<x;i++)
        can[s[i]]++;
    while (r<n)
    {
        if (check()) return true;
        can[s[l++]]--;
        can[s[++r]]++;
    }
    return false;
}

int main()
{
    cin>>n>>s;
    int l=1;
    int r=n;
    for (auto i:s)
        want[i]=true;
    while (r-l>1)
        if (check((l+r)/2)) r=(l+r)/2;
        else l=(l+r)/2;
    if (check(l)) cout<<l;
    else cout<<r;
}