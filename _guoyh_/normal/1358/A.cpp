# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, a, b;
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%d%d", &a, &b);
        printf("%d\n", (a * b + 1) >> 1);
    }
    return 0;
}