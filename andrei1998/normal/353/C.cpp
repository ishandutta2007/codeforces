#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int NMAX = 100000 + 5;

int N;
int a[NMAX];
int sum[NMAX];
string nr;

int getSum(int pos) {
    if (pos >= 0)
        return sum[pos];
    else
        return 0;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++ i) {
        cin >> a[i];
        sum[i] = a[i];
        if (i > 0)
            sum[i] += sum[i - 1];
    }

    cin >> nr;

    int ans = 0;
    int addent = 0;
    for (int bit = N - 1; bit >= 0; -- bit) {
        if (nr[bit] == '1') {
            ans = max(ans, addent + getSum(bit - 1));
            addent += a[bit];
        }
    }
    ans = max(ans, addent);

    cout << ans << '\n';
    return 0;
}