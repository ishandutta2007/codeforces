#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
///-----------------------------------------------------------------------///

signed main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int kk=k/2+k%2;
    kk--;
    cout<<kk/m+1<<' '<<kk%m+1<<' ';
    if (k%2==1) cout<<'L'; else cout<<'R';
}