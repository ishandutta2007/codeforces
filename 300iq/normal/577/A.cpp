#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n, x, S = 0;
    cin >> n >> x;
    for(ll i = 1; i <= n; i++){
        if(x<=i*n && x%i==0){
                S++;
        }
    }
    cout << S;
}