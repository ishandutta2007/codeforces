#include<cstdio>
#include<algorithm>
using namespace std;
int n, C[10], R[4];
int main(){
    int i, j, a;
    char p[3];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s%d",p,&a);
        for(j=0;j<10;j++){
            if((a>>j)&1){
                if(p[0]=='&'){
                    continue;
                }
                if(p[0]=='|'){
                    C[j] = 2;
                }
                if(p[0]=='^'){
                    C[j] ^= 1;
                }
            }
            else{
                if(p[0]=='&'){
                    C[j] = 3;
                }
                if(p[0]=='|') continue;
                if(p[0]=='^') continue;
            }
        }
    }
    for(i=0;i<10;i++){
        R[C[i]] += (1<<i);
    }
    printf("3\n");
    printf("^ %d\n",R[1]);
    printf("| %d\n",R[2]);
    printf("& %d\n",1023-R[3]);
}