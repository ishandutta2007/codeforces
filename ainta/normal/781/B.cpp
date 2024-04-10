#include<cstdio>
#include<algorithm>
using namespace std;
int n, E[2010][2010];
struct point{
    int a, b;
}w[2010];
bool v[2010];
int ord[2010], cnt, SCC[2010];
void DFS1(int a){
    int i;
    v[a] = true;
    for(i=1;i<=n+n;i++){
        if(E[a][i] && !v[i]) DFS1(i);
    }
    ord[++cnt] = a;
}
void DFS2(int a){
    int i;
    SCC[a] = cnt;
    for(i=1;i<=n+n;i++){
        if(E[i][a] && !SCC[i]) DFS2(i);
    }
}
void Print(int a){
    printf("%c%c%c\n",(a/26/26)+'A', (a/26)%26+'A', a%26+'A');
}
int main(){
    int i, j;
    char pp[22], qq[22];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s%s",pp,qq);
        w[i].a = (pp[0]-'A')*26*26 + (pp[1]-'A')*26 + (pp[2]-'A');
        w[i].b = (pp[0]-'A')*26*26 + (pp[1]-'A')*26 + (qq[0]-'A');
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j)continue;
            if(w[i].a == w[j].a){
                E[i][n+i]=E[j][n+j]=1;
            }
            if(w[i].a == w[j].b){
                E[i][j]=E[j+n][i+n]=1;
            }
            if(w[i].b == w[j].b){
                E[i+n][j] = E[j+n][i]=1;
            }
        }
    }
    for(i=1;i<=n+n;i++){
        if(!v[i]) DFS1(i);
    }
    cnt = 0;
    for(i=n+n;i>=1;i--){
        if(!SCC[ord[i]]){
            cnt++;
            DFS2(ord[i]);
        }
    }
    for(i=1;i<=n;i++){
        if(SCC[i]==SCC[i+n]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for(i=1;i<=n;i++){
        if(SCC[i] < SCC[i+n])Print(w[i].b);
        else Print(w[i].a);
    }
}