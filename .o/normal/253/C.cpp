#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;
#define N_ 105
#define M_ 100005
int N, D[N_];

struct S{
    int x, y,c; S(){}
    S(int x,int y,int c=0): x(x), y(y), c(c) {}
} st, en;

S Que[10000005]; int Qf, Qr;
int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
bool Ck[N_][M_];

int main(){
#ifdef ABCDTEST
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    int i, j, k;
    
    scanf("%d",&N);
    for(i = 1; i <= N; i++) scanf("%d",&D[i]);
    scanf("%d%d%d%d",&st.x,&st.y,&en.x,&en.y);
    
    Que[++Qr] = st; Ck[st.x][st.y] = 1;
    while(Qf < Qr){
        S fr = Que[++Qf]; 
        if(fr.x == en.x && fr.y == en.y) return 0 & printf("%d\n",fr.c);
        for(i = 0; i < 4; i++){
            S nxt = S(fr.x + dx[i], fr.y + dy[i], fr.c + 1);
            if(D[nxt.x] + 1 < nxt.y) nxt.y = D[nxt.x] + 1;
            if(nxt.x < 1 || nxt.x > N || nxt.y < 1) continue;
            if(Ck[nxt.x][nxt.y]) continue;
            if(nxt.x == en.x && nxt.y == en.y) return 0 & printf("%d\n",nxt.c);
            Que[++Qr] = nxt; Ck[nxt.x][nxt.y] = 1;
        }
    }
    
    puts("oops");
    return 0;
}