#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    cin >> x;
    int r=0;
    if (x.size()>2) {
    for (int i = 0; i < x.size()-2; ++i) {
        if (x[i]=='Q') {
            for (int j = i+1; j < x.size()-1; ++j) {
                if (x[j]=='A') {
                    for (int t = j+1; t < x.size(); ++t) {
                        if (x[t]=='Q') {
                            ++r;
                        }
                    }
                }
            }
        }
    }
    }
    cout << r;
}