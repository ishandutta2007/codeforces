#include <cstdio>
#include <deque>
using namespace std;

int N, K;
deque <int> D;

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
        D.push_back(i);
    for (int i = 1; i <= N; i++) 
        if (i > N - K && (i - N + K) % 2) { printf("%d ", D.back()); D.pop_back(); }
        else { printf("%d ", D.front()); D.pop_front(); }
    puts("");
    return 0;
}