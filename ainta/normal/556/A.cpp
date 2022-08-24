#include<stdio.h>
#include<algorithm>
using namespace std;
int n, C[2];
char p[201000];
int main()
{
    int i;
    scanf("%d",&n);
    scanf("%s",p);
    for(i=0;p[i];i++)C[p[i]-'0']++;
    printf("%d\n",abs(C[0]-C[1]));
}