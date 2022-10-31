#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define sync                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ld long double
#define M_PI 3.14159265358979323846
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int MAXN=10005;
const int MAXN2=777;
const ll MOD=1234567891LL;
const ll INF=1e18+7;
main(){
    ll a, b, g, xmin = INF;
    cin >> a >> b;
    ll x[a];
    for(int i=0;i<a;i++) x[i]=0;
    for(int i=0;i<b;i++) {cin >> g;x[g-1]++;}
    for(int i=0;i<a;i++) xmin = min(xmin, x[i]);
    cout << xmin;
}