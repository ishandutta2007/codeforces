#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    b--;
    c-=2;
    cout << (3*min(a, min(b, c))) + 3 << endl;
}