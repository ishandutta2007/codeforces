#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct AA{
    long long g, len;
};
char p[101000];
int Next[101000][3], Bef[101000][3];
long long Mod = 1000000007, ML = 1000000006;
AA Exp(int b, int e, int dep);
long long Pow(long long a, long long b){
    long long r = 1;
    while(b){
        if(b%2)r=r*a%Mod;
        b/=2;a=a*a%Mod;
    }
    return r;
}
AA Number(int b, int e, long long mod){
    int i;
    long long s = 0;
    for(i=b;i<=e;i++){
        s=(s*10+p[i]-'0')%mod;
    }
    AA ret;
    ret.g = s, ret.len = e-b+1;
    return ret;
}
AA ConCate(AA a, AA b){
    AA ret;
    ret.g = (a.g * Pow(10, b.len) + b.g)% Mod;
    ret.len = (a.len + b.len) % ML;
    return ret;
}
AA Make(long long B6, long long B7, long long E6, long long E7, long long T, long long len){
    AA ret;
    ret.len = len;
    if(T == 1){
        ret.g = (B7+E7)*(E7-B7+Mod+1) % Mod * Pow(2, Mod-2) % Mod;
        return ret;
    }
    long long inv = Pow(T+Mod-1, Mod-2), TP = Pow(T, E6-B6+ML);
    ret.g = ((TP*T + Mod-1)%Mod * E7%Mod * inv%Mod - T * ( (E7-B7+Mod) * TP % Mod - (TP + Mod - 1) * inv % Mod + Mod) % Mod * inv % Mod + Mod)%Mod;
    return ret;
}
AA Get(int b, int e, int ck){ // (1 ~ p[b-e]) % Mod
    AA ret;
    ret.g=0,ret.len=0;
    int i;
    long long M6 = 0, M7 = 0, B6 = 1, B7 = 1, E6 = 0, E7 = 0, tt = 1;
    for(i=b;i<=e;i++){
        M6=(M6*10+p[i]-'0')%ML;
        M7=(M7*10+p[i]-'0')%Mod;
        tt=tt*10%Mod;
        if(i==e)break;
        E6=(E6*10+9)%ML;
        E7=(E7*10+9)%Mod;
        AA tp = Make(B6,B7,E6,E7,tt,(i-b+1) * (E6-B6+1+ML)%ML);
        ret = ConCate(ret, tp);
        B6=B6*10%ML;
        B7=B7*10%Mod;
    }
    if(ck){
        for(i=b;i<=e;i++){
            if(i==b && p[i]!='1')break;
            if(i!=b && p[i]!='0')break;
        }
        if(i==e+1)return ret;
        M6=(M6+ML-1)%ML, M7 = (M7+Mod-1)%Mod;
    }
    AA tp = Make(B6,B7,M6,M7,tt,(e-b+1) * (M6-B6+1+ML)%ML);
    ret = ConCate(ret, tp);
    return ret;
}
AA Repeat(int b, int e, AA a){
    AA tp = Number(b, e, ML);
    AA ret;
    ret.len = tp.g * a.len % ML;
    if(tp.g == 0)ret.g = 0;
    else{
        if(a.len==0)ret.g = a.g * Number(b,e,Mod).g % Mod;
        else ret.g = (Pow(10, a.len * tp.g) + Mod - 1) * Pow(Pow(10, a.len) + Mod - 1, Mod - 2) % Mod * a.g % Mod;
    }
    return ret;
}
AA Term(int b, int e, int dep){
    int pv;
    if(Next[b][2] <= e){
        return Repeat(b, Next[b][2] - 1, Exp(Next[b][2] + 1, e - 1, dep+1));
    }
    if(Next[b][0] <= e){
        pv = Next[b][0];
        AA tp1 = Get(b, pv-1, 1), tp2 = Get(pv+1, e, 0);
        long long L2 = (tp2.len - tp1.len + ML)%ML;
        AA ret;
        ret.g = (tp2.g - Pow(10, L2) * tp1.g % Mod + Mod)%Mod;
        ret.len = L2;
        return ret;
    }
    return Number(b, e, Mod);
}
vector<int>PTH[101000];
AA Exp(int b, int e, int dep){
    int pv = -1;
    if(!PTH[dep].empty()){
        int t = lower_bound(PTH[dep].begin(),PTH[dep].end(),e+1) - PTH[dep].begin();
        if(t)pv = PTH[dep][t-1];
    }
    if(b <= pv){
        return ConCate(Exp(b,pv-1,dep), Term(pv+1, e, dep));
    }
    return Term(b, e, dep);
}
int main(){
    int i, n;
    scanf("%s",p+1);
    for(i=1;p[i];i++);
    n = i-1;
    for(i=1;i<=n;i++){
        Bef[i][0] = Bef[i-1][0],Bef[i][1] = Bef[i-1][1],Bef[i][2] = Bef[i-1][2];
        if(p[i]=='-')Bef[i][0] = i;
        if(p[i]=='+')Bef[i][1] = i;
        if(p[i]==')')Bef[i][2] = i;
    }
    for(i=0;i<3;i++)Next[n+1][i] = n+1;
    for(i=n;i>=1;i--){
        Next[i][0] = Next[i+1][0],Next[i][1] = Next[i+1][1], Next[i][2] = Next[i+1][2];
        if(p[i]=='-')Next[i][0] = i;
        if(p[i]=='+')Next[i][1] = i;
        if(p[i]=='(')Next[i][2] = i;
    }
    int d = 0;
    for(i=1;i<=n;i++){
        if(p[i]=='(')d++;
        if(p[i]==')')d--;
        if(p[i]=='+')PTH[d].push_back(i);
    }
    printf("%lld\n",Exp(1,n,0).g);
}