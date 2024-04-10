#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100005;

int N, sum;
char s[MAXN];
int a[MAXN];

int main() {
    scanf("%s", s);
    
    N = strlen(s);
    for (int i = 0; i < N; i++) { 
        a[i] = 1;
        if (s[i] != '(') a[i] = -1;
        sum += a[i];
    }
    
    if (sum < 0) { puts("-1"); return 0; }
    
    for (int i = N - 1; i >= 0; i--) 
        if (s[i] == '#') { a[i] -= sum; break; }
        
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i];
        if (sum < 0) { puts("-1"); return 0; }
    }
    
    for (int i = 0; i < N; i++) 
        if (s[i] == '#') printf("%d\n", -a[i]);
        
    return 0;
}