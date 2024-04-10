#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
int main(){
    SPEED;
    bool i1, i2, i3, i4, d1, d2, d3, d4, t1, t2, o1;
    cin >> i1 >> i2 >> i3 >> i4;
    d1 = i1 ^ i2;
    d2 = (i3 || i4);
    d3 = i2 && i3;
    d4 = i1 ^ i4;
    t1 = d1 && d2;
    t2 = (d3 || d4);
    o1 = t1 ^ t2;
    cout << o1?1:0;
}