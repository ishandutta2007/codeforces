#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll counter = 0;
    ll bcounter = 0;
    ll i = 0;
    while(i < n){
        bcounter = 0;
        while(a[i] <= a[i+1]){
            if(bcounter == 0 && n != 1){
            bcounter += 2;
            }
            else{
                bcounter++;
            }
            if(i < n-2){
                i++;
            }
            else{
                break;
            }
        }
        counter = max(counter, bcounter);
        if(i < n-2){
            i++;
        }
        else{
            break;
        }
    }
    if(counter != 0){
        cout << counter;
    }
    else{
        cout << 1;
    }
}