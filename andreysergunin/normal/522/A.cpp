#include <cstdio>
#include <cstring>
#include <cctype>

const int N = 201;

char names[N][25];
int h[N];
char s[25];

int main() {
    strcpy(names[0],"polycarp"); h[0]=1;
    int n, ans=0;
    scanf("%d\n",&n);
    for (int i=1; i<=n; i++) {
        scanf("%s reposted %s",names[i],s);
        for (int j=0; j<strlen(names[i]); j++)
            names[i][j] = tolower(names[i][j]);
        for (int j=0; j<strlen(s); j++)
            s[j] = tolower(s[j]);
        for (int j=0; j<i; j++) {
            if (strcmp(names[j],s)==0) {
                h[i] = h[j]+1;
                if (h[i]>ans) ans = h[i];
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}