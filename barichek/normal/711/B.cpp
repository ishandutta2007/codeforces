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

#define int ll

int sum_1[arr],sum_2[arr];

main()
{
    int n;
    cin>>n;
    if (n==1) return cout<<1, 0;
    int a[n][n];
    int xx,yy;
    int sum_d1=0;
    int sum_d2=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            cin>>a[i][j];
            sum_1[i]+=a[i][j];
            sum_2[j]+=a[i][j];
            if (i==j) sum_d1+=a[i][j];
            if (i==n-j-1) sum_d2+=a[i][j];
            if (a[i][j]==0)
                xx=i,yy=j;
        }
    a[xx][yy]=xx==0?sum_1[1]-sum_1[xx]:sum_1[0]-sum_1[xx];
    if (a[xx][yy]<=0) return cout<<-1, 0;
    for (int i=0;i<arr;i++)
        sum_1[i]=0,
        sum_2[i]=0;
    sum_d1=0;
    sum_d2=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            sum_1[i]+=a[i][j];
            sum_2[j]+=a[i][j];
            if (i==j) sum_d1+=a[i][j];
            if (i==n-j-1) sum_d2+=a[i][j];
            if (a[i][j]==0)
                xx=i,yy=j;
        }
    int want=sum_d1;
    if (want!=sum_d2) return cout<<-1, 0;
    for (int i=0;i<n;i++)
        if (want!=sum_1[i]||want!=sum_2[i]) return cout<<-1, 0;
    cout<<a[xx][yy];
}