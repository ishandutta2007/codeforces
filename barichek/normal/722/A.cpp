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
    int a,b;
    cin>>n;
    scanf("%d:%d",&a,&b);
    if (n==12)
    {
        if (a==0) cout<<0<<1;
        elif (a>=13)
            if (a%10==0)
                cout<<1<<a%10;
            else
                cout<<0<<a%10;
        else cout<<a/10<<a%10;

        cout<<":";

        if (b>=60) cout<<0<<b%10;
        else cout<<b/10<<b%10;
    }
    if (n==24)
    {
        if (a>=24) cout<<0<<a%10;
        else cout<<a/10<<a%10;

        cout<<":";

        if (b>=60) cout<<0<<b%10;
        else cout<<b/10<<b%10;
    }
}