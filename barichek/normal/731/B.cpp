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

main()
{
    int n;
    cin>>n;
    vi a;
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    for (int i=0;i<n;i++)
    {
        if (a[i]%2==1)
        {
            if (i!=n-1&&a[i+1]!=0)
                a[i+1]--;
            else
                return cout<<"NO", 0;
        }
    }
    cout<<"YES";
}