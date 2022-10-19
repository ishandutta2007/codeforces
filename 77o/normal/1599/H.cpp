#include <bits/stdc++.h>

using namespace std;

int ask(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int d;
    cin >> d;
    return d;
}

int main() {
    ios::sync_with_stdio(false);

    const int N = 1000'000'000;
    int ld = ask(1, 1);
    int lu = ask(1, N);
    int rd = ask(N, 1);
    int ru = ask(N, N);

    int du = ask((lu + (N - ru)) / 2, N);
    int dd = ask((ld + (N - rd)) / 2, 1);
    int dl = ask(1, (ld + (N - lu)) / 2);
    int dr = ask(N,(rd + (N - ru)) / 2);

    cout << "! " << dl + 1 << ' ' << dd + 1 << ' ' << N - dr << ' ' << N - du << endl;
    cout.flush();
    return 0;
}