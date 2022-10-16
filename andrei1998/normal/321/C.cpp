#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 100005;

char labels[NMAX];
vector <int> graph[NMAX];

int sz[NMAX];
void compute_szs(int node, int father) {
    sz[node] = 1;
    for (auto it: graph[node])
        if (!labels[it] && it != father) {
            compute_szs(it, node);
            sz[node] += sz[it];
        }
}

int all;
int centroid;
void find_centroid(int node, int father) {
    int biggest = 0;
    for (auto it: graph[node])
        if (!labels[it] && it != father) {
            find_centroid(it, node);
            if (sz[it] > biggest)
                biggest = sz[it];
        }

    if (biggest <= all / 2 && all - sz[node] <= all / 2)
        centroid = node;
}

void DEI(int node, char label) {
    compute_szs(node, 0);

    all = sz[node];
    find_centroid(node, 0);

    node = centroid;
    labels[node] = label;

    for (auto it: graph[node])
        if (!labels[it])
            DEI(it, label + 1);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;

    int a, b;
    for (int i = 1; i < n; ++ i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DEI(1, 'A');

    for (int i = 1; i <= n; ++ i)
        cout << labels[i] << " \n"[i == n];
    return 0;
}