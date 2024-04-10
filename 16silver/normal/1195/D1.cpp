#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100000][20];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    int k = strlen(s[0]);
    long long ans = 0LL;
    for(int i=0;i<n;i++){
        long long temp = 0LL;
        for(int j=0;j<k;j++){
            temp = (temp * 100LL + (s[i][j]-'0')*11LL)%998244353LL;
        }
        temp %= 998244353LL;
        ans = (ans + temp*n) % 998244353LL;
    }
    printf("%lld\n",ans);
}