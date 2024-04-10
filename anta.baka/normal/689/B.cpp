#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int INF = 1000000000;
vector<int> a(N), d(N, INF);

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> a[i], a[i]--;

    queue<int> q;
    q.push(0);
    d[0] = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        if(v+1 < n && d[v+1] == INF)
            d[v+1] = d[v] + 1, q.push(v+1);

        if(v && d[v-1] == INF)
            d[v-1] = d[v] + 1, q.push(v-1);

        if(d[a[v]] == INF)
            d[a[v]] = d[v] + 1, q.push(a[v]);
    }

    for(int i=0; i<n; i++)
        cout << d[i] << ' ';
}