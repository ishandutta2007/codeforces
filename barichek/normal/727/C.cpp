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

void get_info(int a,int b)
{
    cout<<"? "<<a<<" "<<b<<endl;
}

main()
{
    int n;
    cin>>n;
    vi ans;
    ans.resize(n);
    get_info(1,2);
    int dop1;
    cin>>dop1;
    get_info(1,3);
    int dop2;
    cin>>dop2;
    get_info(2,3);
    int dop3;
    cin>>dop3;
    ans[1]=(dop1+dop3-dop2)/2;
    ans[0]=dop1-ans[1];
    ans[2]=dop3-ans[1];
    for (int i=3;i<n;i++)
    {
        int dop;
        get_info(1,i+1);
        cin>>dop;
        ans[i]=dop-ans[0];
    }
    cout<<"! ";
    for (auto i:ans)
        cout<<i<<" ";
}