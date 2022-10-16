#include <iostream>
#include <set>
#include <string>

using namespace std;

set <string> ballA;

int main()
{
    ios_base :: sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    string str;
    for (int i = 1; i <= N; ++ i) {
        cin >> str;
        ballA.insert(str);
    }

    int common = 0;
    for (int i = 1; i <= M; ++ i) {
        cin >> str;
        if (ballA.count(str))
            ++ common;
    }

    N -= common;
    M -= common;

    bool turn = 0;
    while (1) {
        if (!turn) {
            if (common > 0)
                -- common;
            else if (N > 0)
                -- N;
            else {
                cout << "NO\n";
                return 0;
            }
            turn = true;
        }
        else {
            if (common > 0)
                -- common;
            else if (M > 0)
                -- M;
            else {
                cout << "YES\n";
                return 0;
            }
            turn = false;
        }
    }
    return 0;
}