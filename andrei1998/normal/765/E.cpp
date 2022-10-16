#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int NMAX = 2 * 100000 + 5;

int N;
vector <int> graph[NMAX];

int deg[NMAX];

int whatLen[NMAX];
bool out[NMAX];

queue <int> q;

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);

        deg[a] ++;
        deg[b] ++;
    }

    for (int i = 1; i <= N; ++ i)
        if (deg[i] == 1)
            q.push(i);

    int rem = N;

    int node;
    while (!q.empty()) {
        node = q.front();
        rem --;
        q.pop();

        if (!rem)
            break;

        bool same = true;
        int val = 0;
        for (auto it: graph[node])
            if (out[it]) {
                if (val == 0)
                    val = whatLen[it];
                else if (val != whatLen[it]) {
                    same = false;
                    break;
                }
            }

        if (!same) {
            cout << "-1\n";
            return 0;
        }

        whatLen[node] = 1 + val;
        out[node] = true;
        deg[node] --;

        for (auto it: graph[node])
            if (!out[it]) {
                deg[it] --;
                if (deg[it] == 1)
                    q.push(it);
            }
    }

    //Last node
    vector <int> vals;
    for (auto it: graph[node])
        if (out[it])
            vals.push_back(whatLen[it]);
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

    if (vals.size() > 2) {
        cout << "-1\n";
        return 0;
    }

    int sum = 0;
    for (auto it: vals)
        sum += it;
    while (sum % 2 == 0)
        sum /= 2;
    cout << sum << '\n';
    return 0;
}