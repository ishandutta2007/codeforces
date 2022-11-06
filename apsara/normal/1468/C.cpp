#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

set<PII> S;

queue<PII> Q;

const int N = 500000 + 9;

bool vis[N];

int main(){
    int q;
    scanf("%d", &q);
    int cnt = 0;
    for (int i = 1; i <= q; ++i){
        int opt;
        scanf("%d", &opt);
        if (opt == 1){
            int m;
            scanf("%d", &m);
            ++cnt;
            Q.push({cnt, m});
            S.insert({m, -cnt});
        }
        else if (opt == 2){
            while (vis[Q.front().first]) Q.pop();
            int id = Q.front().first;
            int m = Q.front().second;
            printf("%d ", id);
            S.erase({m, -id});
            vis[id] = true;
        }
        else {
            int id = -(S.rbegin()->second);
            S.erase(--S.end());
            printf("%d ", id);
            vis[id] = true;
        }
    }
    printf("\n");
    return 0;
}