#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 22;
const int maxM = (1 << maxN) + 11;

int n, m, msk, i, x, cnt;
bool on[maxM * 2];
queue<int> Q;

void bfs(int node) {
    int i, to;

    on[node] = false;
    Q.push(node);
    while (!Q.empty()) {
        node = Q.front();
        Q.pop();

        if (node < m) {
            to = (msk ^ node);
            if (on[m + to]) {
                on[m + to] = false;
                Q.push(m + to);
            }
        } else {
            node -= m;
            for (i = 0; i < n; i++) {
                if (((node >> i) & 1) == 0) continue;
                to = (node ^ (1 << i));
                if (on[m + to]) {
                    on[m + to] = false;
                    Q.push(m + to);
                }
            }
            
            to = node;
            if (on[to]) {
                on[to] = false;
                Q.push(to);
            }
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d", &x);
        on[x] = true;
    }

    m = 1 << n;
    msk = m - 1;
    for (i = 0; i < m; i++) on[m + i] = true;

    for (i = 0; i < m; i++) {
        if (!on[i]) continue;
        bfs(i);
        cnt++;
    }

    printf("%d", cnt);


    return 0;
}