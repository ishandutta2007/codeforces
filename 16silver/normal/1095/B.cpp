#include <cstdio>
#include <algorithm>
using namespace std;
int x[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    sort(x,x+n);
    printf("%d",(x[1]-x[0])>(x[n-1]-x[n-2])?x[n-1]-x[1]:x[n-2]-x[0]);
}