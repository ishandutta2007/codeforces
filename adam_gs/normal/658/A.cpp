#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    int p[n];
    int t[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    int t1=0;
    int p1=0;
    int t2=0;
    int p2=0;
    for (int i = 0; i < n; ++i) {
        t1+=t[i];
        t2+=t[n-i-1];
        p1+=max(0, p[i]-t1*c);
        p2+=max(0, p[n-i-1]-t2*c);
    }
    if (p1>p2) {
        cout << "Limak";
    } else if (p1<p2) {
        cout << "Radewoosh";
    } else {
        cout << "Tie";
    }
}