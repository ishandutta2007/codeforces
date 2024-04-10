#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    cin >> x;
    int p=0;
    int s=0;
    for (int i = 0; i < x.size(); ++i) {
        int q=x[i]-'a';
        s+=min(min(p, q)+26-max(p, q), max(q, p)-min(p, q));
        p=q;
    }
    cout << s;
}