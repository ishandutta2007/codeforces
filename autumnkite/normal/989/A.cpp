#include <cstdio>
#include <cstring>
using namespace std;
char a[105];
int n, b[3];
int main(){
    scanf("%s", a + 1), n = strlen(a + 1);
    for (register int i = 2; i < n; ++i){
        b[0] = b[1] = b[2] = 0;
        if (a[i - 1] != '.') b[a[i - 1] - 'A'] = 1;
        if (a[i] != '.') b[a[i] - 'A'] = 1;
        if (a[i + 1] != '.') b[a[i + 1] - 'A'] = 1;
        if (b[0] && b[1] && b[2]) return printf("Yes"), 0;
    }
    return printf("No"), 0;
}