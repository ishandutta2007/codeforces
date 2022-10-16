#include <iostream>
#include <string>

using namespace std;

const int NMAX = 200000 + 5;

int N;
string str;

bool silent[NMAX];

int nxt(int pos) {
    ++ pos;
    if (pos == N)
        pos = 0;
    return pos;
}

int main()
{
    cin >> N >> str;

    int cntD = 0;
    int cntR = 0;
    for (auto it: str)
        if (it == 'D')
            ++ cntD;
        else
            ++ cntR;

    int pos = 0;
    int d = 0;
    int r = 0;
    while (cntD && cntR) {
        if (d == pos)
            d = nxt(pos);
        if (r == pos)
            r = nxt(pos);

        if (!silent[pos]) {
            if (str[pos] == 'D') {
                while (silent[r] || str[r] == 'D')
                    r = nxt(r);
                silent[r] = true;
                cntR --;
            }
            else {
                while (silent[d] || str[d] == 'R')
                    d = nxt(d);
                silent[d] = true;
                cntD --;
            }
        }

        pos = nxt(pos);
    }

    if (cntD)
        cout << "D\n";
    else
        cout << "R\n";
    return 0;
}