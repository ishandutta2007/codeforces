#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int cnt_combs = 25 * 25 * 25 * 25;
const int cards = 8;
const int max_states = 501;

int t, ti, i, bg, states, st, st2, x;
int id[cnt_combs]; //! from unordered state to its id
int who[max_states]; //! from id to base state
vector<int> vv[max_states];

int gr[max_states][max_states];
vector< pair<int, int> > from[max_states][max_states];
ll pp[cards] = {1, 5, 25, 125, 625, 5 * 625, 25 * 625, 125 * 625};

bool done[max_states][max_states];
int win[max_states][max_states];
queue< pair<int, int> > Q;

void pre() {
    int i, st, st2, j, aux, conf;
    vector<int> vals;

    for (st = 0; st < cnt_combs; st++) {
        aux = st;
        vals.clear();

        for (i = 0; i < cards; i++) {
            vals.pb(aux % 5);
            aux /= 5;
        }

        sort(vals.begin(), vals.end());
        for (auto e : vals) aux = aux * 5 + e;

        if (st == aux) {
            id[st] = ++states;
            who[states] = st;
            vv[states] = vals;
        } else {
            id[st] = id[aux];
        }
    }

    cerr << "There are " << states << " states.\n";

    for (st = 1; st <= states; st++) {
        for (st2 = 1; st2 <= states; st2++) {

            for (i = 0; i < cards; i++) {
                if (vv[st][i] == 0) continue;
                if (i != 0) {
                    if (vv[st][i - 1] == vv[st][i])
                        continue;
                }

                for (j = 0; j < cards; j++) {
                    if (vv[st2][j] == 0) continue;
                    if (j != 0) {
                        if (vv[st2][j - 1] == vv[st2][j])
                            continue;
                    }

                    aux = vv[st][i] + vv[st2][j];
                    if (aux >= 5) aux -= 5;

                    conf = who[st];
                    conf += (aux - vv[st][i]) * pp[7 - i];
                    conf = id[conf];

                    //if (st2 == 3 && conf == 4)
                    //    cerr << "d";

                    gr[st][st2]++;
                    from[st2][conf].pb(mp(st, st2));
                }
            }

        }
    }

    cerr << "I finished the edges preprocessing.\n";
    for (st = 1; st <= states; st++) {
        win[st][id[0]] = 0;
        done[st][id[0]] = true;
        Q.push(mp(st, id[0]));
    }

    while (!Q.empty()) {
        st = Q.front().first;
        st2 = Q.front().second;
        Q.pop();

        //if (st == 3 && st2 == 4)
        //    cerr << 'd';

        for (auto fr : from[st][st2]) {
            gr[fr.first][fr.second]--;
            if (done[fr.first][fr.second]) continue;

            if (win[st][st2] == 0) {
                win[fr.first][fr.second] = 1;
                done[fr.first][fr.second] = true;
                Q.push(fr);
            } else {
                if(gr[fr.first][fr.second] == 0) {
                    win[fr.first][fr.second] = 0;
                    done[fr.first][fr.second] = true;
                    Q.push(fr);
                }
            }
        }
    }

    cerr << "I finished the win/lose dp.\n";
    cerr << "I am ready to receive queries ...\n";
    cerr << "\n\n\n";
}

int main()
{
   // freopen("test.in","r",stdin);

    pre();
    cin >> t;

    for (ti = 1; ti <= t; ti++) {
        cin >> bg;

        st = st2 = 0;
        for (i = 0; i < cards; i++) {
            cin >> x;
            st = st * 5 + x;
        }

        for (i = 0; i < cards; i++) {
            cin >> x;
            st2 = st2 * 5 + x;
        }

        st = id[st];
        st2 = id[st2];

        if (bg == 1) swap(st, st2);
        if (done[st][st2] == false) {
            cout << "Deal\n";
        } else {
            if (win[st][st2] == (bg ^ 1))
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
    }

    cerr << "\n\n\n";
    cerr << "Do you have any harder queries ? I am getting bored...\n";

    return 0;
}