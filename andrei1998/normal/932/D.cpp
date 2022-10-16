#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;
const lint INF = numeric_limits <lint> :: max() / 2;

const int NMAX = 400000 + 5;

lint add(lint a, lint b) {
    lint sum = a + b;
    if (sum >= INF)
        sum = INF;
    return sum;
}

int cnt = 1;
lint W[NMAX];
int father[NMAX];
pair <int, lint> jump[20][NMAX];
int h[NMAX];

int main()
{
    //ifstream cin("data.in");
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    lint last2 = 0;

    h[1] = 1;
    while (Q --) {
        int type;
        lint p, q;
        cin >> type >> p >> q;

        if (type == 1) {
            ++ cnt;
            W[cnt] = q ^ last2;
            father[cnt] = p ^ last2;


            const int node = cnt;
            int fat = father[cnt];


            if (W[fat] >= W[node])
                jump[0][node] = make_pair(fat, W[node]);
            else {
                for (int i = 19; i >= 0; -- i) {
                    if (jump[i][fat].first && W[jump[i][fat].first] < W[node])
                        fat = jump[i][fat].first;
                }
                jump[0][node] = make_pair(jump[0][fat].first, W[node]);
            }

            h[node] = 1 + h[jump[0][node].first];
            for (int i = 1; i < 20; ++ i) {
                jump[i][node].first = jump[i - 1][jump[i - 1][node].first].first;
                jump[i][node].second = add(jump[i - 1][node].second,
                                           jump[i - 1][jump[i - 1][node].first].second);
            }
        }
        else if (type == 2) {
            int node = p ^ last2;
            lint X = q ^ last2;
            last2 = 0;

            for (int i = 19; i >= 0; -- i) {
                if ((1 << i) <= h[node] && jump[i][node].second <= X) {
                    last2 += (1 << i);
                    X -= jump[i][node].second;
                    node = jump[i][node].first;
                }
            }

            cout << last2 << '\n';
        }
    }
    return 0;
}