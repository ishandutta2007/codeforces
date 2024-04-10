#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    cin >> n >> m;
    ll ma = -1;
    ll ind = -1;
    ll a;
    for(int i =0;i<n;i++){
        cin >> a;
        if((a+m-1)/m >= ma){
            ma = (a+m-1)/m;
            ind = i;
        }
    }
    cout << ind+1;
    return 0;
}