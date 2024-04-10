#include<cstdio>
#include<algorithm>
using namespace std;
int t, n,a,z,ans;
int main(){
    scanf("%d", &t);
    while(t--){
        ans = 0;
        scanf("%d%d", &n,&z);
        for (int i = 1; i <= n;i++){
            scanf("%d", &a);
            a |= z;
            ans = max(a, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}