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

int n,m;
int a[ar][ar];
int dop[ar][ar];

main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int j1=0;j1<m;j1++)
        for (int j2=0;j2<m;j2++)
        {
            bool ok=true;
            for (int i=0;i<n;i++)
                for (int j=0;j<m;j++)
                    dop[i][j]=a[i][j];
            for (int i=0;i<n;i++)
                swap(dop[i][j1],dop[i][j2]);
            for (int i=0;i<n;i++)
            {
                int cnt=0;
                for (int j=0;j<m;j++)
                    if (dop[i][j]!=j+1)
                        cnt++;
                if (cnt>2) ok=false;
            }
            if (ok) return cout<<"YES", 0;
        }
    cout<<"NO";
}