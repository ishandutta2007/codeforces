#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << min(a, b) << " ";
    a=a+b-2*min(a, b);
    a/=2;
    cout << a;
}