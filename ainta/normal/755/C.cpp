#include<stdio.h>
#include<algorithm>
using namespace std;
int UF[10100], n, w[10100], v[10100];
int Find(int a){
    if(a==UF[a])return a;
    return UF[a] = Find(UF[a]);
}
void Merge(int a, int b){
    a=Find(a),b=Find(b);
    if(a!=b)UF[a]=b;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        UF[i] = i;
    }
    for(i=1;i<=n;i++){
        Merge(i,w[i]);
    }
    for(i=1;i<=n;i++){
        v[Find(i)]=1;
    }
    int c = 0;
    for(i=1;i<=n;i++){
        if(v[i])c++;
    }
    printf("%d\n",c);
}