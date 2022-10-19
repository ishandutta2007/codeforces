#include <bits/stdc++.h>

using namespace std;

int w[117];
int kol[117];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j]=='B') {
                w[i]=1;
                kol[j]=1;
            }
        }
    }
    int p, k;
    for (int i = 0; true; ++i) {
        if (w[i]==1) {
            p=i+1;
            break;
        }
    }
    for (int i = n-1; true; --i) {
        if (w[i]==1) {
            k=i+1;
            break;
        }
    }
    cout << (p+k)/2 << " ";
        for (int i = 0; true; ++i) {
        if (kol[i]==1) {
            p=i+1;
            break;
        }
    }
    for (int i = m-1; true; --i) {
        if (kol[i]==1) {
            k=i+1;
            break;
        }
    }
    cout << (p+k)/2;
}