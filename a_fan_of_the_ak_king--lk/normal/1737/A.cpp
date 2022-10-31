#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,M2=1004535809,M3=469762049,E=524288,N=1000005;
int t,n,k,r,p[N],a,s[26];
char c[N];
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        scanf("%s",c);
        memset(s,0,sizeof(s));
        for(int i=0;c[i];++i)
            ++s[c[i]-'a'];
        for(int i=1;i<=k;++i){
            int j;
            for(j=0;s[j]&&j<n/k;++j)
                --s[j];
            putchar('a'+j);
        }
        putchar('\n');
    }
}