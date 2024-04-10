#include <bits/stdc++.h>

using namespace std;

int w[107];
int k[107];
int im_retarded[107];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        im_retarded[i]=im_retarded[i-1]+i;
    }
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        for (int j = 0; j < n; ++j) {
            if (x[j]=='C') {
                ++w[i];
                ++k[j];
            }
        }
    }
    int wyn=0;
    for (int i = 0; i < n; ++i) {
        wyn+=im_retarded[w[i]-1];
        wyn+=im_retarded[k[i]-1];
    }
    cout << wyn;
}