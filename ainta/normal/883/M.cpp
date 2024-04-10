#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    printf("%d\n",4+max(abs(x1-x2),1)*2+max(abs(y1-y2),1)*2);
}