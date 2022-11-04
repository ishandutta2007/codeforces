#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <iostream>
#include <ctime>
#define M 400010
#define int long long
#define sit set <int>::iterator

using namespace std;

set <int> V[M];

int n, m, k, D[M], A[M], B[M], ans;

signed main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    ans = n;
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        A[i] = a;
        B[i] = b;
        D[a]++;
        D[b]++;
        V[a].insert(b);
        V[b].insert(a);
    }
    vector <int> Tp, Ans;
    Ans.clear();
    Tp.clear();
    for(int i = 1; i <= n; i++) if(D[i] < k) Tp.push_back(i);
    for(int i = m; i >= 1; i--) {
        for(int j = 0; j < Tp.size(); j++) {
            int x = Tp[j];
            if(D[x] <= -100000) continue; else ans--;
            for(sit it = V[x].begin(); it != V[x].end(); it++) {
                V[*it].erase(x);
                if(--D[*it] < k) Tp.push_back(*it);
            }
            V[x].clear();
            D[x] = -100000;
        }
        Ans.push_back(ans);
        Tp.clear();
        if(!V[A[i]].count(B[i])) continue;
        D[A[i]]--;
        D[B[i]]--;
        V[A[i]].erase(B[i]);
        V[B[i]].erase(A[i]);
        if(D[A[i]] < k) Tp.push_back(A[i]);
        if(D[B[i]] < k) Tp.push_back(B[i]);
    }
    for(int i = (int) Ans.size() - 1; i >= 0; i--) printf("%lld\n", Ans[i]);
    return 0;
}