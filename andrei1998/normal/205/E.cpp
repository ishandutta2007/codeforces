#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>

#define lint long long int
using namespace std;

int N;
string A, B;

vector <int> freqA[30];
vector <int> freqB[30];

double ans;
void solve(vector <int> a, vector <int> b) {
    int j = -1;
    lint sum = 0;
    for (auto i: a) {
        while (j + 1 < b.size() && b[j + 1] <= i) {
            ++ j;
            sum += b[j];
        }

        ans += (N - i + 1LL) * sum;
    }

    //Si invers
    swap(a, b);

    j = -1;
    sum = 0;
    for (auto i: a) {
        while (j + 1 < b.size() && b[j + 1] < i) {
            ++ j;
            sum += b[j];
        }

        ans += (N - i + 1LL) * sum;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> N;

    cin >> A;
    A = " " + A;
    cin >> B;
    B = " " + B;

    for (int i = 1; i <= N; ++ i) {
        freqA[A[i] - 'A' + 1].push_back(i);
        freqB[B[i] - 'A' + 1].push_back(i);
    }

    for (int i = 1; i <= 26; ++ i)
        solve(freqA[i], freqB[i]);

    lint cnt = 0;
    for (int i = 1; i <= N; ++ i)
        cnt += (N - i + 1LL) * (N - i + 1LL);
    double res = ans / cnt;

    cout << fixed << setprecision(9) << res << '\n';
    return 0;
}