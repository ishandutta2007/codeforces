#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
ll a[100001];
int main(){
    ll n,m,x,d;
    cin >> n >>m;
    ll s = 0;
    ll di = 0;
    ll ma = (n*(n-1)/2);
    ll mi;
    if(n%2==1){
        mi = (n/2)*(n/2+1);
    } else {
        mi = (n/2)*(n/2);
    }
    for(int i =0;i<m;i++){
        cin >> x >> d;
        s+=x;
        if(d >= 0){
            di = di + d*ma;
        } else {
            di = di + d*mi;
        }
    }
    cout.precision(16);
    cout << s + ( (di /1.0) / (n/1.0));
    return 0;
}