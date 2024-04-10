# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int sz, t;
char s[NR];
bool check(){
    for (int i = 1; i <= sz; i++)
        if (s[i] != s[1]) return false;
    return true;
}
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%s", s + 1);
        sz = strlen(s + 1);
        if (check()) printf("%s\n", s + 1);
        else {
            for (int i = 1; i <= sz; i++) printf("01");
            putchar('\n');
        }
    }
    return 0;
}