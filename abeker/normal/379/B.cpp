#include <cstdio>
using namespace std;

int n, a;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { 
        scanf("%d", &a);
        if (!a) { printf(i < n - 1 ? "R" : "\n"); continue; }
        for (; a > 1; a--) 
            printf(i < n - 1 ? "PRL" : "PLR"); 
        printf(i < n - 1 ? "PR" : "P\n");
    }  
    return 0;
}