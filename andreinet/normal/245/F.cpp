#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int LMAX = 5000005;

char error[LMAX];

int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int sums[20];

struct Error {
    int time;
    string timeText;
};

pair<int, string> format(char err[]) {
    int m = 10 * (err[5] - '0') + err[6] - '0';
    int d = 10 * (err[8] - '0') + err[9] - '0';


    int dayTime = 24 * 60 * 60;
    int time = dayTime * (sums[m - 1] + d - 1);
    
    int h = 10 * (err[11] - '0') + err[12] - '0';
    int min = 10 * (err[14] - '0') + err[15] - '0';
    int sec = 10 * (err[17] - '0') + err[18] - '0';

    time += h * 60 * 60 + min * 60 + sec;

    return make_pair(time, string(err, 19));
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    for (int i = 1; i <= 12; ++i) {
        sums[i] = sums[i - 1] + days[i - 1];
    }

    int n, m;
    cin >> n >> m;
    cin.get();

    vector<Error> errors;
    while (cin.getline(error, LMAX)) {
        int time;
        string timeText;
        tie(time, timeText) = format(error);
        errors.push_back({time, timeText});
    }

    int k = SZ(errors);
    for (int i = 0, j = 0; i < k; ++i) {
        while (errors[i].time - errors[j].time >= n) {
            ++j;
        }
        if (i - j + 1 >= m) {
            cout << errors[i].timeText << '\n';
            return 0;
        }
    }

    cout << "-1\n";
}