#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MOD=1000003;
lli power(lli a,lli p) {
    lli ret=1;
    while(p) {
        if(p&1) ret=ret*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ret;
}
lli inv(lli a) {return power(a,MOD-2);}

struct mat{
    lli a[11][11];
    mat(bool e=false) {
        init(e);
    }
    void init(bool e) {
        for(int i=0;i<11;i++)for(int j=0;j<11;j++) {
            if(i==j && e) a[i][j]=1;
            else a[i][j]=0;
        }
    }
    void swap_a(int i,int j) {
        for(int k=0;k<11;k++) swap(a[i][k],a[j][k]);
    }
    mat eli() {
        mat ret(true);
        for(int i=0;i<11;i++) {
            int idx=-1;
            for(int j=i;j<11;j++) if(a[j][i]) {
                idx=j;
                break;
            }
            assert(idx!=-1);
            swap_a(i,idx);
            ret.swap_a(i,idx);
            
            lli v=inv(a[i][i]);
            for(int k=0;k<11;k++) a[i][k] = a[i][k]*v%MOD, ret.a[i][k]=ret.a[i][k]*v%MOD;
            
            for(int j=i+1;j<11;j++) if(a[j][i]){
                lli x=a[j][i];
                for(int k=0;k<11;k++) {
                    a[j][k] = (a[j][k] - x*a[i][k]%MOD + MOD)%MOD;
                    ret.a[j][k] = (ret.a[j][k] - x*ret.a[i][k]%MOD+MOD)%MOD;
                }
            }
        }
        for(int i=10;i>=0;i--) {
            for(int j=i-1;j>=0;j--) {
                lli x=a[j][i];
                for(int k=0;k<11;k++) {
                    a[j][k] = (a[j][k] - x*a[i][k]%MOD + MOD)%MOD;
                    ret.a[j][k] = (ret.a[j][k] - ret.a[i][k]*x%MOD +MOD)%MOD;
                }
            }
        }
        return ret;
    }
    mat mul(mat rhs) {
        mat ret;
        for(int i=0;i<11;i++)for(int j=0;j<11;j++)for(int k=0;k<11;k++) {
            ret.a[i][j] = (ret.a[i][j] + a[i][k]*rhs.a[k][j]%MOD)%MOD;
        }
        return ret;
    }
}a;

int main() {
    for(int i=0;i<11;i++) {
        a.a[i][0]=1;
        for(int j=1;j<11;j++) a.a[i][j] = a.a[i][j-1]*(i+1)%MOD;
    }
    mat ia = a.eli();

    lli val[11],arr[11]={0,};
    for(int i=0;i<11;i++) {
        printf("? %d\n",i+1);
        fflush(stdout);
        scanf("%lld",&val[i]);
    }
    for(int i=0;i<11;i++) {
        for(int j=0;j<11;j++) arr[i]=(arr[i] + ia.a[i][j]*val[j]%MOD)%MOD;
    }

    for(int i=0;i<MOD;i++) {
        lli ret=0;
        for(int j=0;j<11;j++) ret = (ret + arr[j]*power(i,j))%MOD;
        if(ret==0) {
            printf("! %d\n",i);
            fflush(stdout);
            return 0;
        }
    }
    printf("! -1\n");
    fflush(stdout);

    return 0;
}