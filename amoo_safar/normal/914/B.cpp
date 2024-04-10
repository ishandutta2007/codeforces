#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
ll a[100000];

int main(){
    ll n;
    cin >> n;
    for(int i =0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    ll j =1;
    ll cnt = 1;
    while(j < n){
        if(a[j] == a[j-1]) cnt ++;
        else{
            if(cnt %2 == 1){
                cout << "Conan";
                return 0;
            }
            cnt = 1;
        }
        j++;
    }
    if(cnt %2 == 1){
        cout << "Conan";
        return 0;
    }
    cout << "Agasa" ;
    return 0;
}