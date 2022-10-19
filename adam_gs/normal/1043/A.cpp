#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    int m = 0, s1=0, s2=0;
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
        m=max(m,tab[i]);
        s1+=tab[i];
    }
    for (int i = 0; i < n; ++i) {
        s2+=m-tab[i];
    }
    if (s2>s1) {
        cout << m;
    } else {
        s1-=s2;
        s1/=n;
        cout << s1+m+1;
    }
}