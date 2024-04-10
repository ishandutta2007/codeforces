#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

int N;
int cnt[5];
int sum;
vector <int> num;
vector <pii> tmp;
vector <int> best;
vector <pii> opt;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        cnt[x]++;
    }
}

void apply(int x, int y, int val) {
    cnt[x] -= val;
    cnt[x - 1] += val;
    cnt[y] -= val;
    cnt[y + 1] += val;
}

void find(int depth) {
    if (depth == 2) {
        if (num < best) {
            best = num;
            opt = tmp;
        }
        return;
    }
    
    bool f = false;
    for (int i = 1; i < 5; i++)
        for (int j = 1; j < 4; j++) {
            if (!cnt[i] || !cnt[j]) continue;
            if (i == j && cnt[i] == 1) continue;
            f = true;
            apply(i, j, 1);
            num.push_back(cnt[1] + cnt[2]);
            tmp.push_back(pii(i, j));
            find(depth + 1);
            apply(i, j, -1);
            num.pop_back();
            tmp.pop_back();
        }
    
    if (!f) {
        num.push_back(0);
        find(depth + 1);
        num.pop_back();
    }
}

int solve() {
    if (sum == 1 || sum == 2 || sum == 5) return -1;
    
    int sol = 0;
    while (cnt[1] || cnt[2]) {
        num.clear();
        tmp.clear();
        best.clear();
        for (int i = 0; i < 2; i++)
            best.push_back(4 * N);
        find(0);   
        apply(opt[0].first, opt[0].second, 1);
        sol++;
    } 
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}