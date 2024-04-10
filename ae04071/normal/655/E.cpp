#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int n,k;
char str[1000100];
int d[26],lst[26];

int main() {
    scanf("%d%d",&n,&k);
    scanf("%s",str);

    int m=strlen(str),A=1;
    memset(lst,-1,sizeof(lst));
    for(int i=0;i<m;i++) {
        int c=(A-d[str[i]-'a']+MOD)%MOD;
        A = (A+c)%MOD;
        d[str[i]-'a'] = (d[str[i]-'a']+c)%MOD;
        lst[str[i]-'a']=i;
    }
    for(int i=m;i<m+n;i++) {
        int mx=i,mi=-1;
        for(int j=0;j<k;j++) if(lst[j] < mx) {
            mx = lst[j];
            mi=j;
        }
        
        int c=(A-d[mi]+MOD)%MOD;
        A = (A+c)%MOD;
        d[mi] = (d[mi]+c)%MOD;
        lst[mi]=i;
    }
    printf("%d\n",A);
    
    return 0;
}