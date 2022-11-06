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

#define maxN 30011
#define maxK 211

struct fetcher {
    int id, dif;
};

struct tree {
    int root;
    vector<int> sons;

    tree() {
        root = 0;
        sons = {};
    }
};

int n, k, i, j;
int dist[maxK][maxN];
bool known[maxN];
fetcher F[maxN];
int last[maxN];

vector< pair<int, int> > edges;

void no_solution() {
    printf("-1");
    exit(0);
}

int get_dist(int id1, int id2) {
    if (!known[id1]) {
        cerr << id1 << " not known\n";
        no_solution();
    }

    return dist[ F[id1].id ][id2] - F[id1].dif;
}

void solve_final_case(int root, vector<int>& nodes) {
    sort(nodes.begin(), nodes.end(), [&](int a, int b)->bool const {
        return get_dist(root, a) < get_dist(root, b);
    });

    for (i = 0; i <= nodes.size(); i++) last[i] = -1;
    last[0] = root;

    for (auto e : nodes) {
        int act_dist = get_dist(root, e);
        if (last[act_dist - 1] == -1) {
            cerr << "Can not add node " << e << '\n';
            no_solution();
        }

        edges.pb(mp(last[act_dist - 1], e));
        last[act_dist] = e;
    }
}

void solve(vector<int>& special, vector<int>& normal) {
    if (special.size() == 0) {
        cerr << "No special node\n";
        no_solution();
    }

    if (special.size() == 1) {
        //! there is only one special node
        solve_final_case(special[0], normal);
    } else {
        //! there are a lot of special nodes
        int n1, n2;
        int best = -1;

        for (auto a : special)
            for (auto b : special)
                if (get_dist(a, b) > best)
                    best = get_dist(a, b), n1 = a, n2 = b;

        for (auto e : special)
            if (e != n1 && e != n2)
                normal.pb(e);

        vector<tree> aux = vector<tree>(best + 1);
        aux[0].root = n1;
        aux[best].root = n2;

        for (auto e : normal) {
            int d1 = get_dist(n1, e);
            int d2 = get_dist(n2, e);
            int sum = (best + d1 + d2) / 2;
            if ((best + d1 + d2) % 2 == 1) {
                cerr << "Error while computing distances\n";
                no_solution();
            }

            int pos = sum - d2;

            if (pos < 0 || pos > best) {
                cerr << "Positions is too big or too small\n";
                no_solution();
            }

            if (d1 == pos)
                aux[pos].root = e;
            else
                aux[pos].sons.pb(e);
        }

        vector<int> nxt_n1, nxt_n2;

        for (auto& e: aux) {
            if (e.root == 0) {
                cerr << "Could not find the root of a subtree\n";
                no_solution();
            }

            known[e.root] = true;
            F[e.root] = {F[n1].id, F[n1].dif + get_dist(n1, e.root)};

            if (e.sons.empty()) continue;
            nxt_n1 = nxt_n2 = {};
            nxt_n1.pb(e.root);
            for (auto p : e.sons) {
                if (known[p])
                    nxt_n1.pb(p);
                else
                    nxt_n2.pb(p);
            }

            e.sons.clear();
            solve(nxt_n1, nxt_n2);
        }

        for (i = 1; i < aux.size(); i++)
            edges.pb(mp(aux[i - 1].root, aux[i].root));

    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i <= k; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &dist[i][j]);
            if (dist[i][j] == 0) {
                known[j] = true;
                F[j] = {i, 0};
            }
        }
    }

    vector<int> n1, n2;
    n1 = n2 = {};
    for (i = 1; i <= n; i++) {
        if (known[i])
            n1.pb(i);
        else
            n2.pb(i);
    }

    solve(n1, n2);

    for (auto e : edges)
        cout << e.first << ' ' << e.second << '\n';

    ////! congrats to the author


    return 0;
}