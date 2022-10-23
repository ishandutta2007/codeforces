# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 1000051;
int sz;
char s[NR];
int f[NR];
int main(){
    f[0] = -1;
    scanf("%s", s + 1);
    sz = strlen(s + 1);
    for (int i = 1; i <= sz; i++){
        int p = f[i - 1];
        while (p != -1){
            if (s[p + 1] == s[i]) break;
            p = f[p];
        }
        f[i] = p + 1;
    }
    for (int i = f[sz]; i > 0; i = f[i]){
        int p = 0;
        bool flag = false;
        for (int j = 2; j < sz; j++){
            while (p != -1 && s[p + 1] != s[j]) p = f[p];
            p++;
            if (p == i){
                flag = true;
                break;
            }
        }
        if (flag){
            for (int j = 1; j <= i; j++) printf("%c", s[j]);
            putchar('\n');
            return 0;
        }
    }
    printf("Just a legend\n");
    return 0;
}