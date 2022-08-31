#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[201000];
char p[201000];
int main(){
    int i, Q, a, m;
    scanf("%s",p);
    for(i=0;p[i];i++);
    n=i;
    m = n/2;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&a);
        w[a-1]++;
        w[m]--;
    }
    for(i=1;i<m;i++){
        w[i]+=w[i-1];
    }
    for(i=0;i<m;i++)if(w[i]%2==1)swap(p[i],p[n-1-i]);
    printf("%s\n",p);
}