#include<cstdio>
#include<algorithm>
using namespace std;
char p[10];
int res = 3;
void DFS(int pv, int c){
    if(c>=res)return;
    int i;
    if(pv==6){
        int s = 0;
        for(i=0;i<6;i++){
            if(i<3)s+=p[i];
            else s-=p[i];
        }
        if(s==0)res = c;
        return;
    }
    for(i=0;i<10;i++){
        int ck = 0;
        if(p[pv]!='0'+i){
            ck=1;
        }
        char tp = p[pv];
        p[pv] = '0'+i;
        DFS(pv+1, c+ck);
        p[pv] = tp;
    }
}
int main(){
    int i;
    scanf("%s",p);
    DFS(0,0);
    printf("%d\n",res);
}