#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 300005;

int N;
int a[MAXN];
map <int, bool> bio;
vector <int> last;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void solve() {
    last.push_back(-1);
    for (int i = 0; i < N; i++)
        if (bio[a[i]]) {
            for (int j = i; j > last.back(); j--)
                bio[a[j]] = false;
            last.push_back(i);
        }
        else bio[a[i]] = true;
    
    if (last.size() == 1) {
        puts("-1");
        return;
    }
    
    int sz = last.size();
    last[sz - 1] = max(last[sz - 1], N - 1);
    printf("%d\n", sz - 1);
    for (int i = 1; i < sz; i++)
        printf("%d %d\n", last[i - 1] + 2, last[i] + 1);
}

int main() {
    load();
    solve();
    return 0;
}