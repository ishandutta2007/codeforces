#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 105;

int counts[Nmax][3];
string names[Nmax];

string mess[] = {"If you want to call a taxi, you should call:", "If you want to order a pizza, you should call:", "If you want to go to a cafe with a wonderful girl, you should call:"};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K >> names[i];

        while (K-- > 0) {
            string S;
            cin >> S;

            char last = S[0];
            bool type1 = true, type2 = true;
            for (int j = 1; j < int(S.size()); ++j) {
                char c = S[j];
                if (c == '-') continue;
                if (c != last) type1 = false;
                if (c >= last) type2 = false;
                last = c;
            }

            if (type1) counts[i][0]++;
            else if (type2) counts[i][1]++;
            else counts[i][2]++;
        }
    }


    int maxs[] = {-1, -1, -1};
    vector<int> poss[3];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (counts[i][j] > maxs[j]) {
                poss[j].clear();
                poss[j].push_back(i);
                maxs[j] = counts[i][j];
            } else if (counts[i][j] == maxs[j])
                poss[j].push_back(i);
        }
    }

    for (int i = 0; i < 3; ++i) {
        cout << mess[i];
        bool ok = false;
        for (int p: poss[i]) {
            if (ok) cout << ',';
            cout << ' ' << names[p];
            ok = true;
        }
        cout << ".\n";
    }
}