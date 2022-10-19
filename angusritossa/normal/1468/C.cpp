#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5+5;

int qu;
queue<pair<int,int>> q;
priority_queue<pair<int,int>> pq;
bool used[MAXN];

int main() {
    scanf("%d",&qu);
    int curC = 1;
    for (int i=0;i<qu;i++) {
        int c,m;
        scanf("%d",&c);
        if (c==1) {
            scanf("%d",&m);
            q.push(make_pair(m,-curC));
            pq.push(make_pair(m,-curC));
            curC++;
        } else if (c==2) {
            pair<int,int> ite = q.front();
            q.pop();
            while (used[-ite.second]) {
                ite = q.front();
                q.pop();
            }
            used[-ite.second] = true;
            printf("%d ",-ite.second);
        } else {
            pair<int,int> ite = pq.top();
            pq.pop();
            while (used[-ite.second]) {
                ite = pq.top();
                pq.pop();
            }
            used[-ite.second] = true;
            printf("%d ",-ite.second);
        }
    }
    printf("\n");
}