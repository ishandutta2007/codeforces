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
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int a[ar][ar];
int pref_up_down[ar][ar];
int pref_left_right[ar][ar];

int get_up_down(int q,int l,int r)
{
    return pref_up_down[q][r]-(l==0?0:pref_up_down[q][l-1]);
}

int get_left_right(int q,int l,int r)
{
    return pref_left_right[q][r]-(l==0?0:pref_left_right[q][l-1]);
}

main()
{
    fast;
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            pref_left_right[i][j]=(j==0?0:pref_left_right[i][j-1])+a[i][j];
    for (int j=0;j<m;j++)
        for (int i=0;i<n;i++)
            pref_up_down[j][i]=(i==0?0:pref_up_down[j][i-1])+a[i][j];
    int ans=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            if (a[i][j]) continue;
            if (get_up_down(j,0,i-1))
                ans++;
            if (get_up_down(j,i+1,n-1))
                ans++;
            if (get_left_right(i,0,j-1))
                ans++;
            if (get_left_right(i,j+1,m-1))
                ans++;
        }
    cout<<ans;
}