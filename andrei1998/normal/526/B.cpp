#include <iostream>
#include <vector>
#include <utility>

#define NMAX 2505
using namespace std;

vector <pair <int, int> > graph[NMAX];

int sum[NMAX];
int ans[NMAX];

void dfs (int node) {
    int maxim = 0;
    int suma = 0;

    for (auto it: graph[node]) {
        dfs(it.first);

        ans[node] += ans[it.first];
        suma += (sum[it.first] + it.second);

        if (sum[it.first] + it.second > maxim)
            maxim = sum[it.first] + it.second;
    }

    ans[node] += maxim * graph[node].size() - suma;
    sum[node] = maxim;
}

int main()
{
    int n = 0;
    cin >> n;

    int aux = 1;

    n ++;
    while (n--)
        aux *= 2;
    aux --;

    int light;
    for (int i = 2; i <= aux; i++) {
        cin >> light;
        graph[i / 2].push_back(make_pair(i, light));
    }

    dfs(1);

    cout << ans[1] << '\n';
    return 0;
}