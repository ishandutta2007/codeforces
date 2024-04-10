#include <iostream>
#include <string>

using namespace std;

const int NMAX = 1000000 + 5;

int wait[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int N = str.size();
    str = " " + str;

    bool full = true;
    int cntF = 0;
    int ans = 0;
    wait[0] = -1;
    for (int i = 1; i <= N; ++ i)
        if (str[i] == 'F') {
            ++ cntF;
            if (full)
                continue;
            wait[i] = wait[i - 1] + 1;
            ans = max(ans, wait[i] + i - cntF);
        }
        else {
            full = false;
            wait[i] = wait[i - 1] - 1;
            if (wait[i] < -1)
                wait[i] = -1;
        }

    cout << ans << '\n';
    return 0;
}