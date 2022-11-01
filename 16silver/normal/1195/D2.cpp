#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100000][20];
int l[100000];
long long cnt[11];
long long pow10[22];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        l[i] = strlen(s[i]);
        cnt[l[i]]++;
    }
    pow10[0]=1LL;
    for(int i=1;i<22;i++){
        pow10[i]=(pow10[i-1]*10LL)%998244353LL;
    }
    long long ans = 0LL;
    for(int i=0;i<n;i++){
        for(int j=0;j<l[i];j++){
            for(int k=1;k<11;k++){
                int t = l[i]-j;
                ans = (ans + pow10[t+min(t,k)-1]*cnt[k]*(s[i][j]-'0'))%998244353LL;
                ans = (ans + pow10[t+min(t-1,k)-1]*cnt[k]*(s[i][j]-'0'))%998244353LL;
            }
        }
    }
    printf("%lld\n",ans);
}