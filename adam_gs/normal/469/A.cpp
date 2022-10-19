#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a;
    cin >> a;
    int ta[a];
    for (int i = 0; i < a; ++i) {
        cin >> ta[i];
    }
    sort(ta, ta+a);
    int b;
    cin >> b;
    int tb[b];
    for (int i = 0; i < b; ++i) {
        cin >> tb[i];
    }
    sort(tb, tb+b);
    int la=0, lb=0;
    for (int i = 1; i <= n; ++i) {
        while (ta[la]<i && la<a) ++la;
        while (tb[lb]<i && lb<b) ++lb;
        if (ta[la]!=i && tb[lb]!=i) {
            cout << "Oh, my keyboard!";
            return 0;
        }
    }
    cout << "I become the guy.";
}