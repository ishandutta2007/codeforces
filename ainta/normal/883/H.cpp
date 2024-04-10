#include<cstdio>
#include<algorithm>
using namespace std;
int C[200], res, n, S;
char p[501000], q[501000];
bool Pos(int L){
    int i, c = n/L, j, p1 = 0;
    int ss = (L/2)*c;
    if(ss > S)return false;
    printf("%d\n",c);
    for(i=0;i<c;i++){
        q[L] = 0;
        for(j=0;j<L/2;j++){
            while(C[p1]<2)p1++;
            C[p1]-=2;
            q[j] = q[L-j-1] = p1;
        }
        if(L%2){
            int t = -1;
            for(j=0;j<200;j++){
                if(C[j]%2)break;
                if(C[j])t = j;
            }
            if(j==200){
                C[t]--;
                q[L/2] = t;
            }
            else{
                C[j]--;
                q[L/2] = j;
            }
        }
        printf("%s",q);
        printf(" ");
    }
    return true;
}
int main(){
    int i, j;
    scanf("%d%s",&n,p);
    for(i=0;p[i];i++){
        C[p[i]]++;
    }
    for(i=0;i<200;i++)S += C[i]/2;
    for(i=n;i>=1;i--){
        if(n%i==0){
            if(Pos(i))break;
        }
    }
}