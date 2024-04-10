#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main()
{
    int N, T;
    cin >> N >> T;

    if (N == 1 && T == 10) {
        cout << "-1\n";
        return 0;
    }
    else if (T < 10)
        cout << T;
    else
        cout << '1';
    for (int i = 2; i <= N; ++ i)
        cout << '0';
    cout << endl;
    return 0;
}