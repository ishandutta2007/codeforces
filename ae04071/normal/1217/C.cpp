#include <bits/stdc++.h>
using namespace std;

char str[200100];
int n,pre[200100];

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%s",str+1);
        n = strlen(str+1);

        int pr = 0;
        for(int i=1;i<=n;i++) {
            pre[i] = pr;
            if(str[i]=='1') pr = i;
        }
        
        long long ans=0;
        for(int i=n;i;i--) {
            int val=0;
            for(int j=0;j<18 && i-j>0;j++) {
                val += (str[i-j]-'0') * (1<<j);
                if(str[i-j]=='1') {
                    if(pre[i-j] < i-val+1) ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}