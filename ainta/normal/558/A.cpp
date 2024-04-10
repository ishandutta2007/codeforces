#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
    int x, c;
    bool operator<(const A &p)const{
        return x<p.x;
    }
}w1[110], w2[110];
int n, c1, c2, Res;
int main(){
    int i, x, c;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&c);
        if(x>0){
            w1[c1].x = x;
            w1[c1].c = c;
            c1++;
        }
        else{
            w2[c2].x = -x;
            w2[c2].c = c;
            c2++;
        }
    }
    if(c1)sort(w1,w1+c1);
    if(c2)sort(w2,w2+c2);
    if(c1 == c2){
        for(i=0;i<c1;i++)Res += w1[i].c + w2[i].c;
    }
    else if(c1 > c2){
        for(i=0;i<=c2;i++)Res += w1[i].c + w2[i].c;
    }
    else{
        for(i=0;i<=c1;i++)Res += w1[i].c + w2[i].c;
    }
    printf("%d\n",Res);
}