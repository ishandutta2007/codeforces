#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, IDeg[8010], chk[8010], ODeg[8010];
char p[2010], E[8010][8010];
long long res, FF;
int ToNum(char a){
    if(a<='9')return a-'0';
    return a-'A'+10;
}
struct AA{
    int d, num;
    bool operator <(const AA &p)const{
        return d<p.d;
    }
}ord[8010];
bool CMP(int a, int b){
    return E[a][b];
}
int main(){
    int i, j, k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s",p);
        int c=0;
        for(j=0;j<n/4;j++){
            int t = ToNum(p[j]);
            for(k=3;k>=0;k--){
                E[i][++c]=((t>>k)&1);
                if(E[i][c])IDeg[c]++, ODeg[i]++;
            }
        }
    }
    for(i=1;i<=n;i++){
        ord[i]={IDeg[i],i};
    }
    sort(ord+1,ord+n+1);
    FF=614*n;
    for(i=1;i<=n;i++){
        if(ord[i].d!=i-1)break;
        int x = ord[i].num;
        chk[x]=1;
        res += (n-i)*(FF+1);
    }
    int ed = ord[n].num;
    vector<int>A, B;
    for(i=1;i<=n;i++){
        if(!chk[i]){
            if(E[ed][i])B.push_back(i);
            else A.push_back(i);
        }
    }
    if(A.empty()){
        printf("%lld\n",res);
        return 0;
    }
    sort(A.begin(),A.end(),CMP);
    sort(B.begin(),B.end(),CMP);
    int nA = A.size(), nB=B.size();
    for(i=0;i<nA;i++)ODeg[A[i]]-=nA-i-1;
    for(i=0;i<nB;i++)ODeg[B[i]]-=nB-i-1;
    res += nA*(nA-1)/2+nB*(nB-1)/2;
    for(i=0;i<nA;i++){
        res += nB*2-ODeg[A[i]];
        res += 3*i;
        if(ODeg[A[i]]){
            int t = ODeg[B[ODeg[A[i]]-1]];
            res -= min(t,i);
        }
    }
    for(i=0;i<nB;i++){
        if(ODeg[B[i]])res += 2*nA-ODeg[B[i]];
        else res += 3*nA-ODeg[B[0]];
        res += 3*i;
        if(ODeg[B[i]]){
            int t = ODeg[A[ODeg[B[i]]-1]];
            res -= min(t,i);
        }
    }
    printf("%lld\n",res);
}