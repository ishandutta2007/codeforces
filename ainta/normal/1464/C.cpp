#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, C[26];
char p[101000];
long long T, tot;
void Solve(){
    int i;
    tot=0;
    scanf("%d%lld",&n,&T);
    scanf("%s",p);
    for(i=0;i<n-2;i++){
        C[p[i]-'a']++;
    }
    long long base;
    base = 1<<(p[n-1]-'a');
    base -= 1<<(p[n-2]-'a');
    T-=base;

    for(i=0;i<26;i++){
        tot += (1ll<<i) * C[i];
    }
    tot -= T;
    if(tot < 0 || tot%2){
        puts("No");
        return;
    }
    tot/=2;
    for(i=25;i>=0;i--){
        long long c = tot>>i;
        tot -= min(c,(long long)C[i]) << i;
    }
    if(tot)puts("No");
    else puts("Yes");
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}