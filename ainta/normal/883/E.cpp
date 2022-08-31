#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, v[30], vv[30], R[30];
char p[60], q[1010][60];
int main(){
    int i, j;
    scanf("%d",&n);
    scanf("%s",p);
    for(i=0;p[i];i++){
        if(p[i]>='a' &&p[i]<='z'){
            v[p[i]-'a'] = 1;
        }
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%s",q[i]);
        int chk = 0;
        for(j=0;j<n;j++){
            if(q[i][j]!=p[j] && p[j]!='*')chk = 1;
            if(p[j] == '*' && v[q[i][j]-'a']) chk = 1;
        }
        if(chk)continue;
        for(j=0;j<26;j++)vv[j]=0;
        for(j=0;j<n;j++){
            if(p[j]=='*')vv[q[i][j]-'a'] = 1;
        }
        for(j=0;j<26;j++)if(!vv[j])R[j] = 1;
    }
    int res = 0;
    for(i=0;i<26;i++)if(!R[i]) res++;
    printf("%d\n",res);
}