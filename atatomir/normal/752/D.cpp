#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

string aux;

struct piece {
    string s;
    int val;
    int inv;

    void read() {
        cin >> s >> val;
        aux = s;
        reverse(aux.begin(), aux.end());

        if (s == aux) {
            inv = 2;
        } else {
            if (s < aux) {
                inv = 0;
            } else {
                inv = 1;
                s = aux;
            }
        }
    }

    bool operator<(const piece& who)const {
        return s < who.s;
    }
};


int n, k, i, j;
piece P[maxN];

vector<int> who[3];
int best, ans;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> k;
    for (i = 1; i <= n; i++) P[i].read();
    sort(P + 1, P + n + 1);

    for (i = 1; i <= n; i = j) {
        who[0].clear();
        who[1].clear();
        who[2].clear();

        for (j = i; j <= n && P[i].s == P[j].s; j++)
            who[ P[j].inv ].pb(P[j].val);

        sort(who[0].begin(), who[0].end());
        sort(who[1].begin(), who[1].end());
        sort(who[2].begin(), who[2].end());

        if (P[i].inv == 2) {
            while (who[2].size() >= 2) {
                if (who[2][who[2].size() - 2] + who[2].back() > 0) {
                    auto a = who[2].back(); who[2].pop_back();
                    auto b = who[2].back(); who[2].pop_back();

                    ans += a + b;
                    best = max(best, -a);
                    best = max(best, -b);
                } else {
                    break;
                }
            }

            for (auto e : who[2])
                best = max(best, e);

            continue;
        }

        while (!who[0].empty() && !who[1].empty()) {
            auto a = who[0].back();
            auto b = who[1].back();

            if (a + b <= 0) break;
            who[0].pop_back();
            who[1].pop_back();

            ans += a + b;
            /*best = max(best, -a);
            best = max(best, -b);*/
        }

        /*for (auto e : who[0])
            best = max(best, e);
        for (auto e : who[1])
            best = max(best, e);*/
    }

    printf("%d", ans + best);


    return 0;
}