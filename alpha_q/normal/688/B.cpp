#include <bits/stdc++.h>

using namespace std;

string A, B;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin >> A; B = A;
    reverse(B.begin(), B.end());
    cout << A + B << endl;
    return 0;
}