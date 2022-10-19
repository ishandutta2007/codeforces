#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    string b="";
    int w = 0;
    for (int i = 0; i < a.size(); i+=2) {
        if (a[i]==a[i+1]) {
            ++w;
            if (a[i]=='a') {
                a[i]='b';
            } else {
                a[i]='a';
            }
        }
        b+=a[i];
        b+=a[i+1];
    }
    cout << w << '\n' << b;
}