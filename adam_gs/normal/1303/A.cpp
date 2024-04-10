#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string x;
        cin >> x;
        int p = 0;
        while (p<x.size() && x[p]=='0') {
            ++p;
        }
        int k=x.size()-1;
        while (k>=0 && x[k]=='0') {
            --k;
        }
        int r = 0;
        while (p<k) {
            if (x[p]=='0') {
                ++r;
            }
            ++p;
        }
        cout << r << '\n';
    }
}