#pragma GCC optimize("O3")
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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int phi(int n)
{
    int res=n;
    for (int i=2;i*i<=n;i++)
        if (n%i==0)
        {
            while (n%i==0)
                n/=i;
            res-=res/i;
        }
    if (n>1)
        res-=res/n;
    return res;
}

main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=(k+1)/2;i++)
    {
        if (n==1) break;
        else
            n=phi(n);
    }
    cout<<n%md;
}