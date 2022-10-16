#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 500000 + 5;

int n, c;

vector <int> vects[NMAX];

bool fail;
int mars[2 * NMAX];

int cnt;
void add_comp(vector <int> &a, vector <int> &b) {
    for (int i = 0; i < a.size() && i < b.size(); ++ i)
        if (a[i] != b[i]) {
            if (a[i] < b[i]) {
                ++ cnt;

                int x = 0;
                int y = c - b[i];

                mars[x] ++;
                mars[y + 1] --;

                x = c - a[i] + 1;
                y = c - 1;

                mars[x] ++;
                mars[y + 1] --;
            }
            else {
                ++ cnt;
                int x = c - a[i] + 1;
                int y = c - b[i];

                mars[x] ++;
                mars[y + 1] --;
            }

            return ;
        }

    if (a.size() > b.size())
        fail = true;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> c;
    for (int i = 1; i <= n; ++ i) {
        int sz;
        cin >> sz;

        for (int j = 0; j < sz; ++ j) {
            int val;
            cin >> val;

            vects[i].push_back(val);
        }
    }

    for (int i = 1; i < n; ++ i)
        add_comp(vects[i], vects[i + 1]);

    if (fail) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= c + 1; ++ i)
        mars[i] += mars[i - 1];

    for (int i = 0; i <= c; ++ i) {
        if (mars[i] == cnt) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}