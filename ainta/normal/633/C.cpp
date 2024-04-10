#include<stdio.h>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;
unordered_map<int,int>Map[10100];
char p[10100];
char q[1100000];
int BE[101000], Path[101000], D[101000];
int n, m;
long long Mod2 = 1000000009, t1, t2, tp;
int main(){
    int i, pv = 0, j, t;
    scanf("%d",&n);
    scanf("%s",p+1);
    for(i=1;i<=n/2;i++){
        swap(p[i],p[n+1-i]);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        BE[i] = pv;
        scanf("%s",q+pv);
        t1 = 0, t2 = 0;
        for(j=pv;q[j];j++){
            if(q[j]<='Z')tp = q[j]-'A';
            else tp = q[j]-'a';
            t2=(t2*26+tp)%Mod2;
        }
        Map[j-pv][t2] = i;
        pv = j+1;
    }
    D[0] = 1;
    for(i=1;i<=n;i++){
        t1 = 1, t2 = 0;
        for(j=1;j<=1000&&j<=i;j++){
            tp = p[i-j+1]-'a';
            t2=(t2+t1*tp)%Mod2;
            if(D[i-j]){
                t = Map[j][t2];
                if(t){
                    D[i]=1;
                    Path[i] = t;
                    break;
                }
            }
            t1=t1*26%Mod2;
        }
    }
    pv = n;
    while(pv){
        t = pv;
        for(i=BE[Path[pv]];q[i];i++){
            printf("%c",q[i]);
            t--;
        }
        printf(" ");
        pv = t;
    }
}