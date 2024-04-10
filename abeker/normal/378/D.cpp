#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M, S;
pii bug[MAXN], student[MAXN];
int pass[MAXN], cnt[MAXN];
int who[MAXN];
set < pii > act;

void load() {
    scanf("%d%d%d", &N, &M, &S);
    
    for (int i = 0; i < M; i++) {
        int x; scanf("%d", &x);
        bug[i] = pii(x, i);
    }
    
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        student[i] = pii(x, i);
    }   
    
    for (int i = 0; i < N; i++)
        scanf("%d", pass + i);
}

bool check(int val) {
    act.clear(); 
    for (int i = 0; i < N; i++) 
        cnt[i] = val;
        
    int pos = N - 1, sum = 0, last = -1;
    for (int i = M - 1; i >= 0; i--) {
        for (; pos >= 0 && student[pos].first >= bug[i].first; pos--) 
            act.insert(pii(pass[student[pos].second], student[pos].second));
        if (act.empty()) return 0;
        if (last == -1) last = act.begin() -> second;
        if (cnt[last] == val) sum += pass[last];
        who[bug[i].second] = last;
        if (--cnt[last] == 0) { 
            act.erase(pii(pass[last], last)); 
            last = -1;
        }
        if (sum > S) return 0;   
    }
    
    return 1;
}

void solve() {
    sort(bug, bug + M);
    sort(student, student + N);
    
    int lo = 1, hi = M + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    
    if (!check(lo)) {
        puts("NO");
        return;
    }
    
    puts("YES");
    for (int i = 0; i < M; i++)
        printf("%d ", ++who[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}