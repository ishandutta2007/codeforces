#include <bits/stdc++.h>

#define mod 1000000007
#define lint long long int
#define mp make_pair
#define pb push_back
#define lsb(x) ((x) & (-(x)))
using namespace std;

class Aib {
public:
    vector <int> aib;

    Aib () {
        aib.clear();
    }

    void init (int n) {
        aib.resize(n + 3, 0);
    }

    void update (int pos, int val) {
        pos ++;
        for (; pos < aib.size(); pos += lsb(pos))
            aib[pos] += val;
    }

    int query (int pos) {
        pos ++;
        int ans = 0;
        for (; pos; pos -= lsb(pos))
            ans += aib[pos];
        return ans;
    }

    int query (int st, int dr) {
        if (st > dr)
            swap(st, dr);
            st++;
        return query(dr) - query(st - 1);
    }
};

class Path {
public:
    vector <int> path;
    Aib aib;
};

vector <Path> paths;
int which_path[100005];
int which_pos[100005];

int vertex_which_path[100005];
int vertex_which_pos[100005];

vector <pair <int, int> > graph[100005];
bitset <100005> vis;

void dfs (int node, int where) {
    vertex_which_path[node] = where;
    vertex_which_pos[node] = paths[where].path.size() - 1;
    vis[node] = true;

    for (auto it: graph[node])
        if (!vis[it.first]) {
            paths[where].path.push_back(it.second);
            dfs(it.first, where);
        }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int n = 0;
    cin >> n;

    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;

        graph[a].push_back(make_pair(b, i));
        graph[b].push_back(make_pair(a, i));
    }

    int center = 1;
    for (int i = 1; i <= n; i++)
        if (graph[i].size() > 2) {
            center = i;
            break;
        }

    vis[center] = 1;
    for (auto it: graph[center]) {
        paths.push_back(Path());
        paths.back().path.push_back(it.second);

        dfs(it.first, paths.size() - 1);
    }

    int j;
    for (int i = 0; i < paths.size(); i++) {
        for (j = 0; j < paths[i].path.size(); j++) {
            which_path[paths[i].path[j]] = i;
            which_pos[paths[i].path[j]] = j;
        }

        paths[i].aib.init(paths[i].path.size());
    }

    vertex_which_path[center] = -1;

    int q = 0;
    cin >> q;

    int tip, aux;
    while (q--) {
        cin >> tip >> a;

        if (tip == 1) {
            paths[which_path[a]].aib.update(which_pos[a], -1);
        }
        else if (tip == 2) {
            paths[which_path[a]].aib.update(which_pos[a], 1);
        }
        else if (tip == 3) {
            cin >> b;

            if (vertex_which_path[a] == vertex_which_path[b] && a != center) {
                aux = paths[vertex_which_path[a]].aib.query(vertex_which_pos[a], vertex_which_pos[b]);

                if (aux)
                    cout << "-1\n";
                else
                    cout << abs(vertex_which_pos[a] - vertex_which_pos[b]) << '\n';
            }
            else if (a != center && b != center){
                aux = paths[vertex_which_path[a]].aib.query(vertex_which_pos[a]) + paths[vertex_which_path[b]].aib.query(vertex_which_pos[b]);
                if (aux)
                    cout << "-1\n";
                else
                    cout << vertex_which_pos[a] + vertex_which_pos[b] + 2 << '\n';
            }
            else {
                if (a == center) {
                    if (b == center) {
                        cout << "0\n";
                        continue ;
                    }
                    else
                        swap(a, b);
                }

                if (b == center) {
                    aux = paths[vertex_which_path[a]].aib.query(vertex_which_pos[a]);
                    if (aux)
                        cout << "-1\n";
                    else
                        cout << vertex_which_pos[a] + 1 << '\n';
                }
            }
        }
    }

    return 0;
}