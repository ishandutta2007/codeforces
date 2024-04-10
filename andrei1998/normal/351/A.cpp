#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2000 + 5;

void print(int nr) {
    cout << nr / 1000 << '.' << setfill('0') << setw(3) << (nr % 1000) << endl;
}

int main()
{
    //freopen("data.in", "r", stdin);

    int N;
    cin >> N;

    int zeroes = 0;
    vector <int> vals;

    int cnt = N;
    int sum = 0;
    for (int i = 1; i <= 2 * N && cnt; ++ i) {
        int nr; cin >> nr;
        char ch; cin >> ch;
        int val; cin >> val;
        if (val == 0)
            ++ zeroes;
        else
            vals.push_back(val);
        sum += val;
    }

    int best = 1E9;
    for (int use = 0; use <= N && use <= zeroes; ++ use) {
        int vl = sum - 1000 * (N - use);
        if (vl < 0)
            vl *= (-1);
        best = min(best, vl);
    }

    print(best);
    return 0;
}