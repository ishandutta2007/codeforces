#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll z[1000000];
    bool a[300];
    bool l[300];
int main()
{
   ll n;
    ll m, b;
    cin >> n;

    for(ll i = 0; i < n*n; i++){
        cin >> m >> b;
        if(a[m] == false && l[b] == false){
            a[m] = true;
            l[b] = true;
            z[i] = i+1;
        }
    }
    sort(z, z + 1000000);
    for(ll i = 0; i < 1000000; i++){
        if(z[i] != 0){
            cout << z[i] << " ";
        }
    }
}