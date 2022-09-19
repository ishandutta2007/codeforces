#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 200000;
ll a[MAXN];
int main()
{
    ll n,k,f=0;
    cin >> n >> k;
    for(int i =0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    ll t = n;
    for(int i = n-1;i>0;i--){
        if(f==1){
            if(a[i]==a[i-1]) t--;
            else f=0;
        }
        if(a[i]-a[i-1] <=k and f== 0 and a[i]!=a[i-1]){
            t--;
            f=1;
        }
        //cout << t << a[i]<< endl;
    }
    cout << t;
    return 0;
}