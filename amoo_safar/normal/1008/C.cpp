#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
ll a[100000];
int main(){
    ll n ;
    cin >> n ;
    for(int i =0; i<n;i++) cin >> a[i];
    a[n] = 1000000002;
    n++;
    sort(a,a+n);
    ll c = 0;
    ll t = 0;
    ll tt;
    ll out = 0;
    int f;
    while(c<n-1){
        f = 1;
        tt = 0;
        for(int i = c;i<n;i++){
            if(a[i]==a[c]){
                tt++;
            } else {
                c= i;
                break;
            }
        }
        out+=min(tt,t);
        if(tt > t){
            t = tt;
        }
    }
    cout <<out;
    return 0;
}