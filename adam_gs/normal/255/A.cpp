#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a=0, b=0, c=0;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        if (i%3==0) {
            a+=p;
        } else if (i%3==1) {
            b+=p;
        } else {
            c+=p;
        }
    }
    if (a>b && a>c) {
        cout << "chest";
    } else if (b>a && b>c) {
        cout << "biceps";
    } else {
        cout << "back";
    }
}