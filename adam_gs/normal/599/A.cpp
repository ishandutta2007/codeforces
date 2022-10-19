#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long w1=a+b+c;
    long long w2=a+c+c+a;
    long long w3=a+a+b+b;
    long long w4=b+b+c+c;
    cout << min(min(w1, w2), min(w3, w4));
}