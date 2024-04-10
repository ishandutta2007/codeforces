#include <iostream>
#include <vector>

using namespace std;

int freq[8];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    while (N --) {
        int val;
        cin >> val;
        ++ freq[val];
    }

    if (freq[7] || freq[5]) {
        cout << "-1\n";
        return 0;
    }

    vector <vector <int> > sol;

    while (freq[3] > 0) {
        sol.push_back({1, 3, 6});
        freq[1] --;
        freq[3] --;
        freq[6] --;
    }

    while (freq[6] > 0) {
        sol.push_back({1, 2, 6});
        freq[1] --;
        freq[2] --;
        freq[6] --;
    }
    while (freq[4] > 0) {
        sol.push_back({1, 2, 4});
        freq[1] --;
        freq[2] --;
        freq[4] --;
    }

    for (int i = 1; i <= 6; ++ i)
        if (freq[i]) {
            cout << "-1\n";
            return 0;
        }

    for (auto it: sol)
        cout << it[0] << ' ' << it[1] << ' '<< it[2] << '\n';
    return 0;
}