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

#define div bleat

int div[arr];

main()
{
    int x,k;
    cin>>x>>k;
    while (k--)
    {
        int type;
        cin>>type;
        if (type==2)
        {
            int div2;
            cin>>div2;
            div[div2]=2;
        }
        else
        {
            int div2,div1;
            cin>>div2>>div1;
            div[div1]=1;
            div[div2]=2;
        }
    }
    int ans1=0;
    int ans2=0;
    for (int i=1;i<x;i++)
        if (div[i]==0) ans2++;
    for (int i=1;i<x;i++)
    {
        if (div[i]!=0) continue;
        if (i<x-1&&div[i+1]!=2)
            div[i+1]=1,
            ans1++;
        else
            ans1++;
    }
    cout<<ans1<<" "<<ans2;
}