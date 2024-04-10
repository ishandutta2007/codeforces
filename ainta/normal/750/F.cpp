#include<stdio.h>
#include<algorithm>
using namespace std;
int TC, H, n, w[1010][3], C[1010];
int L[110], be, ed;
void Query(int a){
    printf("? %d\n", a);
    fflush(stdout);
    scanf("%d",&C[a]);
    int i;
    for(i=0;i<C[a];i++){
        scanf("%d",&w[a][i]);
    }
}
void Answer(int a){
    printf("! %d\n",a);
    fflush(stdout);
}
int Q[1010];
void Do(int a){
    int head = 0, tail = 0, x, i;
    Q[++tail] = a;
    while(head < tail){
        x = Q[++head];
        if(head == 7){
            Answer(x);
            return;
        }
        Query(x);
        if(C[x] == 2){
            Answer(x);
            return;
        }
        for(i=0;i<C[x];i++){
            if(!C[w[x][i]]){
                Q[++tail] = w[x][i];
            }
        }
    }
}
int main(){
    int i;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d",&H);
        n = (1<<H) - 1;
        int a = 1;
        be = 10, ed = 9;
        for(i=1;i<=n;i++)C[i] = 0;
        while(1){
            Query(a);
            L[++ed] = a;
            if(C[a] == 1)break;
            for(i=0;i<C[a];i++){
                if(!C[w[a][i]]){
                    a = w[a][i];
                    break;
                }
            }
        }
        a = -1;
        for(i=0;i<C[1];i++){
            if(!C[w[1][i]]){
                a = w[1][i];
                break;
            }
        }
        if(a!=-1){
            while(1){
                Query(a);
                L[--be] = a;
                if(C[a] == 1)break;
                for(i=0;i<C[a];i++){
                    if(!C[w[a][i]]){
                        a = w[a][i];
                        break;
                    }
                }
            }
        }
        int hh = (ed-be) / 2;
        a = L[(be+ed)/2];
        while(H-hh > 4){
            for(i=0;i<C[a];i++){
                if(!C[w[a][i]]){
                    a = w[a][i];
                    break;
                }
            }
            ed -= hh;
            hh++;
            while(1){
                Query(a);
                L[++ed] = a;
                if(C[a] == 1)break;
                for(i=0;i<C[a];i++){
                    if(!C[w[a][i]]){
                        a = w[a][i];
                        break;
                    }
                }
            }
            hh = (ed-be)/2;
            a = L[(be+ed)/2];
        }
        if(hh == H - 1){
            Answer(a);
            continue;
        }
        for(i=0;i<C[a];i++){
            if(!C[w[a][i]]){
                a = w[a][i];
                break;
            }
        }
        Do(a);
    }
}