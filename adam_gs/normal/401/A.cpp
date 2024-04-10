#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, s=0;
    cin >> n >> m;
    while (n--){
        int a;
        cin >> a;
        s+=a;
    }
    s=max(s, -1*s);
    cout << (s+m-1)/m;
}