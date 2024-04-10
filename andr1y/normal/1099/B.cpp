#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin >> n;
    int i = 1;
    while(i*i<n) i++;
    if(i*i==n) cout << i+i;
    else cout << i+i - (n-(i-1)*(i-1)<=i-1);
}