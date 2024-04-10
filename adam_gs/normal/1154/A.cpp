#include <bits/stdc++.h>

using namespace std;

int main() {
    int T[4];
    cin >> T[0] >> T[1] >> T[2] >> T[3];
    sort(T, T+4);
    cout << T[3]-T[2] << " " << T[3]-T[1] << " " << T[3]-T[0];
}