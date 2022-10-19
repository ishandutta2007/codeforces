#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int r=0;
    while (n--) {
        string x;
        cin >> x;
        if (x=="Tetrahedron") {
            r+=4;
        } else if (x=="Cube") {
            r+=6;
        } else if (x=="Octahedron") {
            r+=8;
        } else if (x=="Dodecahedron") {
            r+=12;
        } else {
            r+=20;
        }
    }
    cout << r;
}