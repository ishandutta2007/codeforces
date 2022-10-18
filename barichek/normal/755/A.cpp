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

bool prime[1000002];

main()
{
    int n;
    cin>>n;
    prime[1]=true;
    for (int i=2;i<=1e6+1;i++)
        if (!prime[i])
            for (int j=2*i;j<=1e6+1;j+=i)
                prime[j]=true;
    for (int m=1;m<=1e3;m++)
        if (prime[n*m+1])
            return cout<<m, 0;
}