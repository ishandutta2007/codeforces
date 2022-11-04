#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> V[4];

int val(int x, int y) {
    if(V[x].empty()) return 0;;
    return !y ? 0 : (y <= V[x].size() ? V[x][y - 1] : V[x].back());
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        char ch[4];
        scanf("%s", ch);
        int x = (ch[0] - '0') * 2 + ch[1] - '0';
        int y;
        scanf("%d", &y);
        V[x].push_back(y);
    }
    for(int i = 0; i < 4; i++) {
        sort(V[i].begin(), V[i].end());
        reverse(V[i].begin(), V[i].end());
        for(int j = 1; j < V[i].size(); j++) V[i][j] += V[i][j - 1];
    }
    if(V[1].size() > V[2].size()) swap(V[1], V[2]);
    int ans = val(3, 23333333), nw = ans, t = V[3].size();
    for(int i = 0; i <= t && i <= V[0].size(); i++) {
        ans = max(ans, val(0, i) + val(1, V[1].size()) + val(2, V[1].size() + t - i) + nw);
    }
    printf("%d\n", ans);
    return 0;
}