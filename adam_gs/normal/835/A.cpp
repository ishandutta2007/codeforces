#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int w1=s*v1+2*t1;
    int w2=s*v2+2*t2;
    if (w1 < w2) {
        cout << "First";
    } else if (w2 < w1) {
        cout << "Second";
    } else {
        cout << "Friendship";
    }
}