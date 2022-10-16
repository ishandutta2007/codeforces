#include <iostream>
#include <string>

using namespace std;

int N, K;

bool works[1005][2010];
char father[1005][2010];

int main()
{
    string str;
    cin >> N >> K;
    cin >> str;
    str = " " + str;

    works[0][K] = true;
    for (int pos = 0; pos < N; ++ pos)
        for (int i = 1; i < 2 * K; ++ i)
            if (works[pos][i]) {
                if (str[pos + 1] == 'D') {
                    works[pos + 1][i] = true;
                    father[pos + 1][i] = 'D';
                }
                else if (str[pos + 1] == 'W') {
                    works[pos + 1][i + 1] = true;
                    father[pos + 1][i + 1] = 'W';
                }
                else if (str[pos + 1] == 'L') {
                    works[pos + 1][i - 1] = true;
                    father[pos + 1][i - 1] = 'L';
                }
                else {
                    works[pos + 1][i] = true;
                    father[pos + 1][i] = 'D';
                    works[pos + 1][i + 1] = true;
                    father[pos + 1][i + 1] = 'W';
                    works[pos + 1][i - 1] = true;
                    father[pos + 1][i - 1] = 'L';
                }
            }

    int col = -100;
    if (works[N][0])
        col = 0;
    else if (works[N][2 * K])
        col = 2 * K;
    if (col == -100) {
        cout << "NO\n";
        return 0;
    }

    int lin = N;
    while (lin) {
        if (father[lin][col] == 'D') {
            str[lin] = 'D';
        }
        else if (father[lin][col] == 'W') {
            str[lin] = 'W';
            col --;
        }
        else if (father[lin][col] == 'L') {
            str[lin] = 'L';
            col ++;
        }
        lin --;
    }

    str = str.substr(1);
    cout << str << '\n';
    return 0;
}