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
    int s,x1,x2;
    int t1,t2;
    int p,d;
    cin>>s>>x1>>x2;
    cin>>t1>>t2;
    cin>>p>>d;
    int time_on_train=0;
    int cnt=0;
    while (true)
    {
        if (p==x1&&abs((p==0&&d==-1?1:p==s&&d==1?s-1:p+d-x2))<abs(p-x2))
            break;
        elif (p==x1)
            cnt++;
        if (cnt==10)
            break;
        p+=d;
        if (p==-1)
            p+=2, d*=-1;
        elif (p==s+1)
            p-=2, d*=-1;
        time_on_train+=t1;
    }
    cout<<min(abs(x1-x2)*t2,time_on_train+abs(x1-x2)*t1);
}