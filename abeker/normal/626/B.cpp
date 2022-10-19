#include <cstdio>
using namespace std;

const int MAXN = 205;
const char c[] = "BGR";

int N;
char s[MAXN];
int cnt[1005];

int main() {
    scanf("%d%s", &N, s);
    
    for (int i = 0; i < N; i++)
        cnt[s[i]]++;
    
    int diff = 0;
    for (int i = 0; i < 3; i++)
        diff += cnt[c[i]] > 0;
    
    if (diff == 1) printf("%c\n", s[0]);
    else if (diff == 3) puts(c);
    else {
        for (int i = 0; i < 3; i++)
            if (cnt[c[i]] < N - 1) printf("%c", c[i]);
        puts("");
    }
     
    return 0;
}