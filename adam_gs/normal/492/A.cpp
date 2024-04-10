#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int p = 1, s=1, w=1;
    for (int i = 2; s<=n; ++i) {
        p+=i;
        s+=p;
        w+=1;
    }
    cout << w-1;
}