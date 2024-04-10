#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int maxn(int a, int b, int c, int d){
    if (a < b)
        a = b;
    if (c < d)
        c = d;
    if (a < c)
        a = c;
    return a;
}
int main (){
    int a, b, c;
    cin >> a >> b >> c;
    cout << maxn((a + b + c), (a * b * c), ((a + b) * c), a * (b + c));
}