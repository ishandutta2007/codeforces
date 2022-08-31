#include<cstdio>
#include<algorithm>
using namespace std;
int n, a, Mn = 1e9, pv;
bool v[101000];
int main(){
    int i, j;
    scanf("%d",&n);
    pv = n;
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        v[a] = true;
        while (v[pv]){
            printf("%d ",pv);
            pv--;
        }
        printf("\n");
    }
}