#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    if (K == 1) {
        cout << "-1\n";
        return 0;
    }

    if (N <= 3)
        cout << "-1\n";
    else if (N == 4) {
        if (K != 3)
            cout << "-1\n";
        else {
            cout << "3\n";
            cout << "1 2\n";
            cout << "2 3\n";
            cout << "3 4\n";
        }
    }
    else {
        if (K == 2) {
            cout << N - 1 << '\n';
            for (int i = 1; i < N; ++ i)
                cout << i << ' ' << i + 1 << '\n';
        }
        else if (K == 3) {
            cout << N - 1 << '\n';
            cout << "1 2\n";
            for (int i = 2; i <= N; ++ i)
                if (i != 3)
                    cout << i << ' ' << 3 << '\n';
        }
        else
            cout << "-1\n";
    }
    return 0;
}