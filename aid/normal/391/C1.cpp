#include <iostream>

using namespace std;

const int MAXN = 16, INF = 1000 * 1000 * 1000 + 5;;
int p[MAXN], e[MAXN];
char won[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> p[i] >> e[i];
    int ans = INF;
    for(int i = 0; i < (1 << n); i++) {
        int sum = 0, w = 0;
        for(int j = 0; j < n; j++)
            if(i & (1 << j)) {
                sum += e[j];
                w++;
                won[j] = true;
            }
            else
                won[j] = false;
        int pos = 0;
        for(int j = 0; j < n; j++)
            if(p[j] + (!won[j]) > w || (p[j] + (!won[j]) == w && !won[j]))
                pos++;
        if(pos < k)
            ans = min(ans, sum);
    }
    cout << (ans == INF? -1 : ans) << '\n';
    return 0;
}