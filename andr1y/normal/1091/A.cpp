#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll gc = c;
    if(gc-1>b) gc = b+1;
    if(gc-2>a) gc = a+2;
    cout << gc*3 - 3;
}