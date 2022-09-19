#include <bits/stdc++.h>
using namespace std;
typedef long ll;
int main(){
    ll x1,x2,y1,y2,x,y;
    cin >> x1>>y1>>x2>>y2 >> x >> y;
    if((abs(x1-x2)%x != 0 )or(abs(y1-y2)%y != 0)) cout << "NO";
    else {
        ll a,b;
        a = abs(x1-x2)/x;
        b = abs(y1-y2)/y;
        //cout << a << b;
        if((a%2)==(b%2)) cout << "YES";
        else cout << "NO";
    }
    return 0;
}