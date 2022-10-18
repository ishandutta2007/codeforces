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

#define int ll

int a,b;

void print(vector<int>& a)
{
    cout<<"YES\n";
    cout<<a.size()<<"\n";
    for (auto i:a)
        cout<<i<<" ";
}

void rec(int cur,vector<int> way)
{
    if (cur>b) return;
    if (cur==b)
    {
        print(way);
        exit(0);
    }
    way.pb(cur*10+1);
    rec(cur*10+1,way);
    way.back()=cur*2;
    rec(cur*2,way);
}

main()
{
    cin>>a>>b;
    rec(a,vector<int>{a});
    cout<<"NO";
}