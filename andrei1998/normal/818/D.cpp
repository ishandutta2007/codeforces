#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int N, A;
int c[NMAX];

int adv[NMAX];

vector <int> freq[10 * NMAX];

bool check(vector <int> &pos) {
    pos.push_back(N + 1);

    int cnt = 0;
    for (auto it: pos) {
        if (cnt < adv[it - 1])
            return false;
        ++ cnt;
    }
    return true;
}

int main()
{
    cin >> N >> A;
    for (int i = 1; i <= N; ++ i) {
        cin >> c[i];
        adv[i] = adv[i - 1];
        if (c[i] == A)
            ++ adv[i];
        freq[c[i]].push_back(i);
    }

    for (int i = 1; i <= 1000000; ++ i)
        if (i != A && check(freq[i])) {
            cout << i << '\n';
            return 0;
        }

    cout << "-1\n";
    return 0;
}