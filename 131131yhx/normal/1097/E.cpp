#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#define M 200010

using namespace std;

typedef long long ll;

int n, A[M], R[M], col[M], Lim[M], Pr[M];

vector <int> Ans[M], mmp[M];

bool calc(int a, int b) {
    b -= a * (a + 1) / 2;
    if(b < 0) return 0;
    return 1;
}

void Solve() {
    //scanf("%d", &n);
    //14
    //3 9 2 12 11 7 14 8 13 1 4 5 10 6
    //n = rand() % 15 + 28;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);//A[i] = i;
    //random_shuffle(A + 1, A + n + 1);
    for(int i = 1; i <= n; i++) col[i] = -1, Pr[i] = 0, R[A[i]] = i;
    int tot = n;
    for(int T = 1; ; T++) {
        vector <int> V(0), nwans(0);
        for(int i = 1; i <= n; i++) Pr[i] = 0;
        for(int i = 1; i <= n; i++) if(col[i] == -1) {
            if(V.empty() || V.back() < A[i]) {
                if(!V.empty()) Pr[A[i]] = V.back();
                V.push_back(A[i]), Ans[(int) V.size() - 1].push_back(A[i]);
            }
            else {
                int w = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
                if(w) Pr[A[i]] = V[w - 1];
                V[w] = A[i];
                Ans[w].push_back(A[i]);
            }
        }
        if(tot && V.size() >= Lim[tot]) { //!!!
            for(int i = V.back(); i; i = Pr[i]) mmp[T].push_back(i), col[R[i]] = T;
            reverse(mmp[T].begin(), mmp[T].end());
            tot -= V.size();
        } else {
            printf("%d\n", T - 1 + V.size());
            for(int i = 1; i < T; i++) {
                printf("%d ", mmp[i].size());
                for(int j = 0; j < mmp[i].size(); j++) printf("%d ", mmp[i][j]);
                putchar('\n');
                mmp[i].clear();
            }
            for(int i = 0; i < V.size(); i++) {
                printf("%d ", Ans[i].size());
                for(int j = 0; j < Ans[i].size(); j++) printf("%d ", Ans[i][j]);
                putchar('\n');
            }
            for(int i = 0; i < V.size(); i++) Ans[i].clear();//!!!
            return;
        }
        for(int i = 0; i < V.size(); i++) Ans[i].clear();
        //clear Ans, mmp
    }
}

int main() {
    int T;
    Lim[1] = 1;
    for(int i = 2; i <= 100000; i++) Lim[i] = ((Lim[i - 1] + 0) * (Lim[i - 1] + 1) / 2 == i - 1) ? Lim[i - 1] + 1 : Lim[i - 1];
    scanf("%d", &T);
    //T = 10000;
    while(T--) {
        Solve();
    }
    return 0;
}