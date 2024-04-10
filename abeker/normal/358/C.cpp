#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;
const string cont[] = {"Stack", "Queue", "Back"};

int N;
int a[MAXN];
priority_queue < pii > Q;
string sol[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void solve() {
    for (int i = 0; i < N; i++)
        if (a[i]) { 
            Q.push(pii(a[i], i));
            sol[i] = "pushFront";
        }
        else {
            int k = min((int)Q.size(), 3);
            sol[i] += k + '0';
            for (int j = 0; j < k; j++) {
                sol[Q.top().second] = "push" + cont[j];
                sol[i] += " pop" + cont[j];
                Q.pop();                
            } 
            while (!Q.empty()) Q.pop();
        }
    for (int i = 0; i < N; i++)
        puts(sol[i].c_str());
}

int main() {
    load();
    solve();
    return 0;
}