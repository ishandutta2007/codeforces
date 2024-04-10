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
#define int long long

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
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

main()
{
    int n,m;
    cin>>n>>m;
    set<string> a;
    a.clear();
    while (n--)
    {
        string s;
        cin>>s;
        a.insert(s);
    }
    set<string> b;
    b.clear();
    while (m--)
    {
        string s;
        cin>>s;
        b.insert(s);
    }
    set<string> dop;
    set<string> dop2;
    for (auto i:a)
        if (b.count(i))
            dop.insert(i),
            b.erase(i);
        else
            dop2.insert(i);
    a=dop2;
    int sz1=a.size();
    int sz2=b.size();
    int sz3=dop.size();
    int cur=0;
    while (true)
    {
        if (cur==0)
        {
            if (sz1+sz3==0)
                return cout<<"NO", 0;
            else
            {
                if (sz3)
                    sz3--;
                else
                    sz1--;
            }
        }
        else
        {
            if (sz2+sz3==0)
                return cout<<"YES", 0;
            else
            {
                if (sz3)
                    sz3--;
                else
                    sz2--;
            }
        }
        cur^=1;
    }
}