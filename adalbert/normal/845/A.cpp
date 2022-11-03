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
int a[arr];
signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=2*n;i++)
        cin>>a[i];
    sort(a+1,a+1+2*n);
    if (a[n]!=a[n+1])
        cout<<"YES"; else cout<<"NO";
}