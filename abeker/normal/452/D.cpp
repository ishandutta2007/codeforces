#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXK = 10001;

int K;
int n[3], t[3];
int a[MAXK];

void load() {
    scanf("%d", &K);
    for (int i = 0; i < 3; i++) 
        scanf("%d", n + i);
    for (int i = 0; i < 3; i++) 
        scanf("%d", t + i);
}

int solve() {
    for (int i = 1; i < K; i++) {
        a[i] = a[i - 1];
        for (int j = 0; j < 3; j++) 
            if (i >= n[j]) 
                a[i] = max(a[i], a[i - n[j]] + t[j]);    
    }
    //for (int i = 0; i < K; i++)  
    //    printf("%d ", a[i]);
    //puts("");
    return a[K - 1] + t[0] + t[1] + t[2];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}