#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

const int NMAX = 5005;
string graph[NMAX];

void solve(const vector <int> &nodes) {
    if (nodes.empty())
        return ;
    int node = nodes.front();

    vector <int> sus;
    vector <int> jos;

    for (int i = 1; i < nodes.size(); ++ i)
        if (graph[node][nodes[i]] == '1')
            jos.push_back(nodes[i]);
        else
            sus.push_back(nodes[i]);

    for (auto it_sus: sus)
        for (auto it_jos: jos)
            if (graph[it_sus][it_jos] == '0') {
                cout << node + 1 << ' ' << it_jos + 1 << ' ' << it_sus + 1 << '\n';
                exit(0);
            }

    solve(sus);
    solve(jos);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++ i)
        cin >> graph[i];

    vector <int> nodes(n);
    for (int i = 0; i < n; ++ i)
        nodes[i] = i;

    solve(nodes);

    cout << "-1\n";
    return 0;
}