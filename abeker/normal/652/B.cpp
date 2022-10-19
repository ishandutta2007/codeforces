#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int N;
int a[MAXN];
int sol[MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
       
    sort(a, a + N);   
    int pos = 0; 
    for (int i = 0; i < N; i++) 
        if (!(i % 2)) sol[i] = a[pos++];
   
    for (int i = 0; i < N; i++)
        if (i % 2) sol[i] = a[pos++];
    
    for (int i = 0; i < N; i++)
        printf("%d ", sol[i]);
    puts("");
    
    return 0;
}