#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;
const int Nmax = 305, mc = 1000;

int A[Nmax];
string Ans[Nmax];

bool filln(string& curr, int sum, int endpos) {
    if (sum < 0) return false;
    for (int i = 0; i < endpos; ++i) {
        curr[i] = '0' + min(sum, 9);
        sum -= min(sum, 9);
    }
    return sum == 0;
}

bool tryt(string& curr, const string& prev, int sum, int step) {
    if (step == -1 || sum < 0) return false;
    if (tryt(curr, prev, sum - (prev[step] - '0'), step - 1)) {
        curr[step] = prev[step];
        return true;
    } else {
        for (curr[step] = prev[step] + 1; curr[step] <= '9'; ++curr[step]) {
            bool ok = filln(curr, sum - (curr[step] - '0'), step);
            if (ok) return true;
        }
        return false;
    }
}

string nextNumber(const string& prev, int sum) {
    string ret(mc, '0');
    tryt(ret, prev, sum, mc - 1);
    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    Ans[0] = string(mc, '0');
    for (int i = 1; i <= N; ++i)
        Ans[i] = nextNumber(Ans[i - 1], A[i]);

    for (int i = 1; i <= N; ++i) {
        while (int(Ans[i].size()) > 1 && Ans[i].back() == '0') Ans[i].pop_back();
        reverse(Ans[i].begin(), Ans[i].end());
        cout << Ans[i] << '\n';
    }
}