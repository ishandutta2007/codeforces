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

bool is_prime(int n)
{
    if (n<=1) return false;
    for (int i=2;i*i<=n;i++)
        if (n%i==0)
            return false;
    return true;
}

int color[arr];

main()
{
    int n;
    cin>>n;
    int cur=1;
    bool ok=false;
    for (int i=2;i<=n+1;i++)
        if (!is_prime(i))
            ok=true;
    cout<<1+ok<<"\n";
    for (int i=2;i<=n+1;i++)
        if (is_prime(i))
            cout<<1<<" ";
        else
            cout<<2<<" ";
    cout<<"\n";
}