#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <pii> vii;
const ld pi = acos(-1);
const int arr = 4*1e5+100;
const ll md = 1e9+7;
const ll base=31;
const int AaA = 'a'-'A';
ld eps=1e-7;

int cnt[1000];

signed main()
{
    int n,x;
    cin>>n>>x;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        cnt[a]++;
    }
    int ans=0;
    for (int i=0;i<x;i++)
        ans+=(cnt[i]==0);
    cout<<ans+cnt[x];
}