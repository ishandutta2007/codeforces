#include <iostream>

using namespace std;

int N, M;
int lastRow[5005];
int tmpRow[5005];
int lastCol[5005];
int tmpCol[5005];

int main()
{
    int K = 0;
    cin >> N >> M >> K;

    for (int i = 1; i <= K; ++ i) {
        int type, where, c;
        cin >> type >> where >> c;

        if (type == 1) {
            lastRow[where] = c;
            tmpRow[where] = i;
        }
        else {
            lastCol[where] = c;
            tmpCol[where] = i;
        }
    }

    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j) {
            if (tmpRow[i] > tmpCol[j])
                cout << lastRow[i];
            else
                cout << lastCol[j];
            cout << " \n"[j == M];
        }
    return 0;
}