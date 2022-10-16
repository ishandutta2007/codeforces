#include <bits/stdc++.h>

using namespace std;

const int NMAX = 150000 + 5;

int N;
int A[NMAX], B[NMAX];

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> A[i] >> B[i];

    vector <int> divs;
    for (int i = 1; i * i <= A[1]; ++ i)
        if (A[1] % i == 0) {
            divs.push_back(i);
            divs.push_back(A[1] / i);
        }
    for (int i = 1; i * i <= B[1]; ++ i)
        if (B[1] % i == 0) {
            divs.push_back(i);
            divs.push_back(B[1] / i);
        }

    sort(divs.begin(), divs.end());
    divs.resize(unique(divs.begin(), divs.end()) - divs.begin());

    for (auto d: divs) {
        if (d == 1)
            continue;
        bool ok = true;
        for (int i = 1; i <= N; ++ i)
            if (A[i] % d != 0 && B[i] % d != 0) {
                ok = false;
                break;
            }

        if (ok) {
            cout << d << endl;
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}