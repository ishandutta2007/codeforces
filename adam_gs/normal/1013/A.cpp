#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int w=0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        w+=a;
    }
    while(n--) {
        int a;
        cin >> a;
        w-=a;
    }
    if (w>=0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}