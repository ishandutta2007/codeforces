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

int cnt[arr];
int ans[arr];

main()
{
    int n;
    cin>>n;
    vi a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    int cur=0;
    for (int i=0;i<n;i++)
    {
        fill(cnt,cnt+10000,0);
        for (int j=i;j<n;j++)
        {
            if (++cnt[a[j]]>cnt[cur]||(cnt[a[j]]==cnt[cur]&&cur>a[j]))
                cur=a[j];
            ans[cur]++;
        }
    }
    for (int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}