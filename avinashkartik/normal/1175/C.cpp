#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll t,n,k;
ll a[500005];

int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        ll m = 1e10;
        ll l = 0;
        for(int i = 0; i < n-k; i++){
            if(a[i+k] - a[i] < m){
                m = a[i+k] - a[i];
                l = i;
            }
        }
        printf("%d\n",(a[l] + a[l+k])/2);
    }
}