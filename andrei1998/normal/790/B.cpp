#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int lint;

const int NMAX = 200000 + 5;

int N, K;
vector <int> graph[NMAX];
lint ans;

lint aux[5];
void add1(int cnt[5], lint sumDist[5]) {
    for (int i = 0; i < K; ++ i)
        aux[(i + 1) % K] = cnt[i];
    for (int i = 0; i < K; ++ i)
        cnt[i] = aux[i];

    for (int i = 0; i < K; ++ i)
        aux[(i + 1) % K] = sumDist[i];
    for (int i = 0; i < K; ++ i)
        sumDist[i] = aux[i];

    sumDist[1 % K] += cnt[1 % K];
}

void subtr1(int cnt[5], lint sumDist[5]) {
    sumDist[1 % K] -= cnt[1 % K];

    for (int i = 0; i < K; ++ i)
        aux[(i + K - 1) % K] = cnt[i];
    for (int i = 0; i < K; ++ i)
        cnt[i] = aux[i];

    for (int i = 0; i < K; ++ i)
        aux[(i + K - 1) % K] = sumDist[i];
    for (int i = 0; i < K; ++ i)
        sumDist[i] = aux[i];
}

int cnt[NMAX][5];
lint sumDist[NMAX][5];

void dfs1(int node, int father) {
    for (int i = 0; i < K; ++ i)
        cnt[node][i] = sumDist[node][i] = 0;

    for (auto it: graph[node])
        if (it != father) {
            dfs1(it, node);
            for (int i = 0; i < K; ++ i) {
                cnt[node][i] += cnt[it][i];
                sumDist[node][i] += sumDist[it][i];
            }
        }

    add1(cnt[node], sumDist[node]);
    ++ cnt[node][0];
}

void dfs2(int node, int father) {
    for (int i = 0; i < K; ++ i)
        ans += sumDist[node][i];

    for (auto it: graph[node])
        if (it != father) {
            add1(cnt[it], sumDist[it]);
            for (int i = 0; i < K; ++ i) {
                cnt[node][i] -= cnt[it][i];
                sumDist[node][i] -= sumDist[it][i];
            }
            add1(cnt[node], sumDist[node]);
            subtr1(cnt[it], sumDist[it]);
            for (int i = 0; i < K; ++ i) {
                cnt[it][i] += cnt[node][i];
                sumDist[it][i] += sumDist[node][i];
            }

            dfs2(it, node);

            for (int i = 0; i < K; ++ i) {
                cnt[it][i] -= cnt[node][i];
                sumDist[it][i] -= sumDist[node][i];
            }
            add1(cnt[it], sumDist[it]);
            subtr1(cnt[node], sumDist[node]);
            for (int i = 0; i < K; ++ i) {
                cnt[node][i] += cnt[it][i];
                sumDist[node][i] += sumDist[it][i];
            }
            subtr1(cnt[it], sumDist[it]);
        }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs1(1, 0);
    dfs2(1, 0);

    cout << ans / 2 << '\n';
    return 0;
}