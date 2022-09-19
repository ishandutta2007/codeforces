#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
ll sum;
int sd(ll n){
    sum =0 ;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main(){
    ll n,s;
    cin >> n >> s;
    ll d =s;
    while(s < n+1){
            //cout << 2;
        if(s-sd(s) >= d) break;
        s++;
    }
    cout <<max((ll)0,n-s+1);
    return 0;
}