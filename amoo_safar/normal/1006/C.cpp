#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
ll const MAXN = 200001;
ll a[MAXN];
int main(){
    ll n,l,r;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    l = a[0];
    r = a[n-1];
    ll i = 0, j = n - 1;
    ll m = 0;
    while(i<j){
        if(l == r) {
            m = max(m,l);
            i ++;
            l+=a[i];
        }
        if(r > l) {
            i ++;
            l += a[i];
        }
        if(l > r){
            j --;
            r += a[j];
        }
    }
    cout << m << endl;
    return 0;
}