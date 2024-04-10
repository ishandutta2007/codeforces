#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 205;

int N, K;
int a[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
}

int solve() {
    int sol = -200005;
    for (int i = 0; i < N; i++) 
        for (int j = i; j < N; j++) {
            vector <int> in, out;
            for (int k = 0; k < N; k++) 
                if (k < i || k > j) out.push_back(a[k]);
                else in.push_back(a[k]);
            sort(in.begin(), in.end());
            sort(out.begin(), out.end());
            for (int k = 0; k < min(K, (int)in.size()) && !out.empty(); k++) 
                if (in[k] < out.back()) {
                    in[k] = out.back();
                    out.pop_back();
                }
            int sum = 0;
            for (int k = 0; k < in.size(); k++)
                sum += in[k];
            sol = max(sol, sum);
        }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}