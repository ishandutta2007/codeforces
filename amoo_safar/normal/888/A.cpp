#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000];
int b[603];
int main(){
    ll n;
    cin >> n;
    for(int i =0;i<n;i++) cin >> a[i];
    ll t =0;
    for(int i=1;i<n-1;i++){
        if((a[i]>a[i-1] and a[i]>a[i+1])or((a[i]<a[i-1] and a[i]<a[i+1])))t++;
    }
    cout << t;
    return 0;
}