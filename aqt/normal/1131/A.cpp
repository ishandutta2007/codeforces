#include <bits/stdc++.h>

using namespace std;

int main(){
    long long w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    cout << w1+w2+2*(h1+h2) + 4 + w1-w2 << endl;
}