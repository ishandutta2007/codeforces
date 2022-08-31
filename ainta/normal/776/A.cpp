#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
char p[101000], q[101000];
int n;
string AA, BB, CC, DD;
int main(){
    int i;
    scanf("%s%s",p,q);
    AA = p, BB = q;
    scanf("%d",&n);
    printf("%s %s\n",p,q);
    for(i=0;i<n;i++){
        scanf("%s%s",p,q);
        CC = p, DD = q;
        if(AA == CC) AA = DD;
        else BB = DD;
        printf("%s %s\n",AA.c_str(), BB.c_str());
    }
}