#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 10005;

vector <int> graph[NMAX];

int main()
{
    int n;
    cin >> n;

    int a, b;
    for (int i = 1; i < n; ++ i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        ans += (graph[i].size() * (graph[i].size() - 1)) / 2;
    cout << ans  << '\n';
    return 0;
}