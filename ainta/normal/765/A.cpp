#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int n, cnt, cc;
char p[10], q[10];
map<string,int>Map;
int main(){
    scanf("%d",&n);
    scanf("%s",p);
    Map[p] = 1;
    int i, j;
    for(j=1;j<=n;j++){
        scanf("%s",p);
        for(i=0;i<3;i++)q[i]=p[i];
        q[3]=0;
        if(Map[q]==1)cc++;
        for(i=0;i<3;i++)q[i]=p[i+5];
        q[3]=0;
        if(Map[q]==1)cc--;
    }
    if(cc==0)printf("home\n");
    else printf("contest\n");
}