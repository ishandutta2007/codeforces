#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int NMAX = 200000 + 5;
const int MMAX = 2 * NMAX;

int N, M, S, T, dS, dT;

vector <pair <int, int> > all_edges;
vector <int> graph[NMAX];

int father[NMAX];
int h[NMAX];

void init() {
    for (int i = 1; i <= N; ++ i)
        father[i] = i, h[i] = 0;
}

int find(int node) {
    if (father[node] != father[father[node]])
        father[node] = find(father[node]);
    return father[node];
}

bool unite(int a, int b) {
    a = find(a), b = find(b);

    if (a == b)
        return false;

    if (h[a] < h[b])
        father[a] = b;
    else {
        if (h[a] == h[b])
            ++ h[a];
        father[b] = a;
    }

    return true;
}

bool is_root[NMAX];
int edge_s[NMAX];
int edge_t[NMAX];

vector <pair <int, int> > final_edges;

bool do_try_no_st() {
    int _dS = dS;
    int _dT = dT;

    vector <int> specials;

    for (int i = 1; i <= N; ++ i)
        if (is_root[i]) {
            int ri = find(i);

            if (!edge_s[ri] && !edge_t[ri])
                return 0;
            else if (edge_s[ri] && !edge_t[ri])
                -- _dS;
            else if (!edge_s[ri] && edge_t[ri])
                -- _dT;
            else if (edge_s[ri] && edge_t[ri])
                specials.push_back(ri);
        }

    if (specials.empty())
        return 0;

    -- _dS;
    -- _dT;

    specials.pop_back();

    for (auto it: specials) {
        if (_dS > 0)
            -- _dS;
        else if (_dT > 0)
            -- _dT;
        else
            return 0;
    }

    if (_dS < 0 || _dT < 0)
        return 0;

    return 1;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= M; ++ i) {
        int a, b;
        cin >> a >> b;

        if (b < a)
            swap(a, b);
        all_edges.push_back(make_pair(a, b));

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cin >> S >> T >> dS >> dT;

    if (T < S) {
        swap(S, T);
        swap(dS, dT);
    }

    bool st = false;
    for (auto it: all_edges)
        if (it.first == S && it.second == T) {
            st = true;
            break;
        }

    init();

    for (auto it: all_edges)
        if (it.first != S && it.first != T && it.second != S && it.second != T)
            unite(it.first, it.second);

    for (int i = 1; i <= N; ++ i)
        if (i != S && i != T) {
            int ri = find(i);
            is_root[ri] = true;
        }

    for (auto it: graph[S])
        if (it != T) {
            int rit = find(it);
            edge_s[rit] = it;
        }

    for (auto it: graph[T])
        if (it != S) {
            int rit = find(it);
            edge_t[rit] = it;
        }

    bool works_no = do_try_no_st();

    if (st && !works_no) {
        final_edges.push_back(make_pair(S, T));
        -- dS;
        -- dT;

        for (int i = 1; i <= N; ++ i)
            if (is_root[i]) {
                int ri = find(i);
                if (!edge_s[ri] && !edge_t[ri]) {
                    cout << "No\n";
                    return 0;
                }
                else if (edge_s[ri] && !edge_t[ri]) {
                    -- dS;
                    final_edges.push_back(make_pair(S, edge_s[ri]));
                }
                else if (!edge_s[ri] && edge_t[ri]) {
                    -- dT;
                    final_edges.push_back(make_pair(T, edge_t[ri]));
                }
                else if (edge_s[ri] && edge_t[ri]) {
                    if (dS > 0) {
                        -- dS;
                        final_edges.push_back(make_pair(S, edge_s[ri]));
                    }
                    else if (dT > 0){
                        -- dT;
                        final_edges.push_back(make_pair(T, edge_t[ri]));
                    }
                    else {
                        cout << "No\n";
                        return 0;
                    }
                }
            }

        for (auto it: all_edges)
            if (it.first != S && it.first != T && it.second != S && it.second != T)
                final_edges.push_back(it);

    }
    else {
        vector <int> specials;

        for (int i = 1; i <= N; ++ i)
            if (is_root[i]) {
                int ri = find(i);
                if (!edge_s[ri] && !edge_t[ri]) {
                    cout << "No\n";
                    return 0;
                }
                else if (edge_s[ri] && !edge_t[ri]) {
                    -- dS;
                    final_edges.push_back(make_pair(S, edge_s[ri]));
                }
                else if (!edge_s[ri] && edge_t[ri]) {
                    -- dT;
                    final_edges.push_back(make_pair(T, edge_t[ri]));
                }
                else if (edge_s[ri] && edge_t[ri])
                    specials.push_back(ri);
            }

        if (specials.empty()) {
            cout << "No\n";
            return 0;
        }

        -- dS;
        -- dT;

        int node = specials.back();
        specials.pop_back();

        final_edges.push_back(make_pair(S, edge_s[node]));
        final_edges.push_back(make_pair(T, edge_t[node]));

        for (auto it: specials) {
            int ri = it;
            if (dS > 0) {
                -- dS;
                final_edges.push_back(make_pair(S, edge_s[ri]));
            }
            else if (dT > 0){
                -- dT;
                final_edges.push_back(make_pair(T, edge_t[ri]));
            }
            else {
                cout << "No\n";
                return 0;
            }
        }

        for (auto it: all_edges)
            if (it.first != S && it.first != T && it.second != S && it.second != T)
                final_edges.push_back(it);
    }

    if (dS < 0 || dT < 0) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";

    init();
    for (auto it: final_edges)
        if (unite(it.first, it.second))
            cout << it.first << ' ' << it.second << '\n';
    return 0;
}