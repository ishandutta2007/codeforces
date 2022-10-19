#include <iostream>
#include <vector>
using namespace std;
long long MOD = 1e9+7;
long long cnt[60];
long long bi[60];

int main(void){
    int t;
    scanf("%d", &t);
    long long b = 1;
    for(int i = 0; i < 60; i++){
        bi[i] = b;
        b *= 2;
        if (b >= MOD) b %= MOD;
    }
    while(t--){
        for(int i = 0; i < 60; i++) cnt[i] = 0;
        int n;
        scanf("%d", &n);
        vector<unsigned long long> xlst(n);
        for(int i = 0; i < n; i++) scanf("%llu", &xlst.at(i));
        for(auto x:xlst){
            for(int i = 0; i < 60; i++){
                if(x >> i & 1) cnt[i]++;
            }
        }
        long long ans = 0;
        long long and_sum;
        long long or_sum;
        for(auto x:xlst){
            and_sum = 0;
            or_sum = 0;
            for(int i = 0; i < 60; i++){
                if (x>>i & 1){
                    or_sum += n * bi[i];
                    and_sum += cnt[i] * bi[i];
                }
                else{
                    or_sum += cnt[i] * bi[i];
                }
                if(or_sum >= MOD) or_sum %= MOD;
                if(and_sum >= MOD) and_sum %= MOD;
            }
            
            ans += and_sum * or_sum;
            if(ans >= MOD) ans %= MOD;
        }
        printf("%lld\n", ans);
    }
}