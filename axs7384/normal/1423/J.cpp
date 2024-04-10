#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int MAXSIZE=10000020;
const int mod=1000000007;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
    buf[fread(buf,1,MAXSIZE,stdin)]='\0';
    bufpos=0;
}
#if NEG
int readint(){
    bool isneg;
    int val=0;
    for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
        bufpos+=(isneg=buf[bufpos]=='-');
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return isneg?-val:val;
}
#else
long long readint(){
    long long val=0;
    for(;!isdigit(buf[bufpos]);bufpos++);
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return val;
}
#endif
char readchar(){
    for(;isspace(buf[bufpos]);bufpos++);
    return buf[bufpos++];
}
int readstr(char* s){
    int cur=0;
    for(;isspace(buf[bufpos]);bufpos++);
    for(;!isspace(buf[bufpos]);bufpos++)
        s[cur++]=buf[bufpos];
    s[cur]='\0';
    return cur;
}
ll dp[65][11];//[0..4]*2^i+(..2^(i-1))
//namespace Write {
char bf[1<<25], st[20], *w=bf;
void flush() {
    fwrite(bf, 1, w-bf, stdout);
    w=bf;
}
inline void pc(register char c) {
    *w++ = c;
}
void print(register int n) {
    register char *t=st;
    do {
        *t++ = n%10+48;
    } while(n/=10);
    while(t-->st)
        pc(*t);
}
//}
int main(){
    init();
    int T=readint();
    while(T--){
        long long x=readint();
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        dp[0][1]=-1;
        for(int i=0;i<=60;i++){
            int a=x>>i&1;
            for(int j=0;j<=9;j++){
                if (j)
                    dp[i][j]+=dp[i][j-1];
                int t=(j+(a^(j%2)))/2;
                dp[i+1][t]+=dp[i][j];
                dp[i+1][t+4]-=dp[i][j];
            }
        }
        int ans=dp[60][0]%mod;
        print(ans);
        pc('\n');
    }
    flush();
//    fprintf(stderr,"%.5f",1.0*clock()/CLOCKS_PER_SEC);
}