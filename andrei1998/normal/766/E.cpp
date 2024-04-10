#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 100000 + 5;

int N;
int a[NMAX];

vector <int> graph[NMAX];

bool val[NMAX];
bool simpleVal[NMAX];

void dfsCompute(int node, int bit, int father) {
    for (auto it: graph[node])
        if (it != father) {
            if (a[it] & (1 << bit))
                simpleVal[it] = 1;
            else
                simpleVal[it] = 0;

            val[it] = val[node] ^ simpleVal[it];
            dfsCompute(it, bit, node);
        }
}

long long int ans = 0;

int sz[NMAX][2];

void dfsSolve(int node, int bit, int father) {
    sz[node][val[node]] = 1;
    sz[node][val[node] ^ 1] = 0;
    for (auto it: graph[node])
        if (it != father) {
            dfsSolve(it, bit, node);

            ans += ((1LL << bit) * sz[it][0] * sz[node][1 ^ simpleVal[node]]);
            ans += ((1LL << bit) * sz[it][1] * sz[node][0 ^ simpleVal[node]]);

            sz[node][0] += sz[it][0];
            sz[node][1] += sz[it][1];
        }


}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];

    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int bit = 0; bit < 20; ++ bit) {
        if (a[1] & (1 << bit))
            val[1] = simpleVal[1] = 1;
        else
            val[1] = simpleVal[1] = 0;
        dfsCompute(1, bit, 0);
        dfsSolve(1, bit, 0);
    }

    for (int i = 1; i <= N; ++ i)
        ans += a[i];
    cout << ans << '\n';
    return 0;
}