#include <iostream>

using namespace std;

int N, M, S, F;

const int NMAX = 300000 + 5;

int l[NMAX];
int r[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> S >> F;

    int where = S;
    for (int i = 0; i < M; ++ i) {
        int t, _l, _r;
        cin >> t >> _l >> _r;

        if (t < NMAX) {
            l[t] = _l;
            r[t] = _r;
        }
        else
            break;
    }

    int tmp = 1;
    while (where != F) {
        if (where < F) {
            if (r[tmp] < where || l[tmp] > where + 1) {
                cout << "R";
                ++ where;
            }
            else
                cout << "X";
        }
        else if (where > F) {
            if (r[tmp] < where - 1 || l[tmp] > where) {
                cout << "L";
                -- where;
            }
            else
                cout << "X";
        }

        ++ tmp;
    }

    return 0;
}