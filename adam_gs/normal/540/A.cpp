#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int w =0;
    for (int i = 0; i < a.size(); ++i) {
        int l1=a[i]-'0', l2=b[i]-'0';
        int w1=abs(l2-l1);
        int w2=min(10-l1, l1)+min(10-l2, l2);
        w+=min(w1, w2);
    }
    cout << w;
}