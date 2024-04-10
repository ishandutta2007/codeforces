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

#define maxN 2000011
#define maxSigma 333

int n, sigma, i, j, S, D;
char s1[maxN], s2[maxN];

int C[maxSigma][maxSigma], F[maxSigma][maxSigma], pay[maxSigma][maxSigma];
vector<int> list[maxSigma];
int dist[maxSigma], prov[maxSigma];
bool inQueue[maxSigma];
queue<int> Q;


int flow, cost;

int get_id(char c) {
    if ('a' <= c && c <= 'z') return c - 'a' + 1;
    return c - 'A' + 26 + 1;
}

char get_lett(int id) {
    if (id <= 26) return 'a' + id - 1;
    return 'A' + id - 1 - 26;
}

bool bellman() {
    memset(prov, 0, sizeof(prov));
    for (i = 1; i <= D; i++) dist[i] = -3 * n;

    Q.push(S);
    inQueue[S] = true;
    dist[S] = 0;
    while (!Q.empty()) {
        int node = Q.front(); Q.pop();
        inQueue[node] = false;
        if (node == D) continue;

        for (auto to : list[node]) {
            if (C[node][to] == F[node][to]) continue;
            if (dist[to] < dist[node] + pay[node][to]) {
                dist[to] = dist[node] + pay[node][to];
                prov[to] = node;
                if (!inQueue[to]) {
                    inQueue[to] = true;
                    Q.push(to);
                }
            }
        }
    }

    if (prov[D] == 0) return false;

    flow++;
    for (int node = D; node != S; node = prov[node]) {
        cost += pay[ prov[node] ][node];
        F[prov[node]][node]++;
        F[node][prov[node]]--;
    }


    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n%s\n%s", &n, &sigma, s1 + 1, s2 + 1);
    S = 2 * sigma + 1; D = S + 1;

    for (i = 1; i <= sigma; i++) {
        list[S].pb(i);
        list[i].pb(S);
        C[S][i] = 1;

        list[sigma + i].pb(D);
        list[D].pb(sigma + i);
        C[sigma + i][D] = 1;
    }

    for (i = 1; i <= sigma; i++) {
        for (j = 1; j <= sigma; j++) {
            list[i].pb(sigma + j);
            list[sigma + j].pb(i);
            C[i][sigma + j] = 1;
        }
    }

    for (i = 1; i <= n; i++) {
        int id1 = get_id(s1[i]);
        int id2 = get_id(s2[i]);

        pay[id1][sigma + id2]++;
        pay[sigma + id2][id1]--;
    }

    while (bellman());

    printf("%d\n", cost);
    for (i = 1; i <= sigma; i++) {
        for (j = 1; j <= sigma; j++) {
            if (F[i][sigma + j] == 1) {
                printf("%c", get_lett(j));
            }
        }
    }


    return 0;
}