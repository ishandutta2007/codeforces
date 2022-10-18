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
const ld eps=1e-6;

///---program start---///

typedef vector< vector<ll> > matrix;

matrix operator *(const matrix a,const matrix& b)
{
    matrix res=a;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            res[i][j]=0;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                res[i][j]=(res[i][j]+a[i][k]*b[k][j]+md)%md;
    return res;
}

const matrix a={{4,0},{-1,2}};

matrix _pow(ll n)
{
    if (n==1) return a;
    if (n%2==1) return a*_pow(n-1);
    matrix dop=_pow(n/2);
    return dop*dop;
}

main()
{
    ll n;
    cin>>n;
    if (n==0) return cout<<1, 0;
    matrix use=_pow(n);
    cout<<(use[0][0]+use[1][0]+md)%md;
}