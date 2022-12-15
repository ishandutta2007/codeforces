#include <bits/stdc++.h>
using namespace std;

char s[500100],t[500100],ans[500100];
int n,m,pi[500100];

void getpi(char *str,int n) {
    int j=0;
    for(int i=1;i<n;i++) {
        while(j!=0 && str[i]!=str[j]) j=pi[j-1];
        if(str[i]==str[j]) pi[i]=++j;
    }
}
int main() {
    scanf("%s%s",s,t);
    n=strlen(s);
    m=strlen(t);

    getpi(t,m);
    
    int c[2]={0,};
    for(int i=0;i<n;i++) c[s[i]-'0']++;
    
    int j=0;
    for(int i=0;i<n;i++) {
        int idx=t[j]-'0';
        if(!c[idx]) {
            for(int j=0;j<c[0]+c[1];j++) {
                if(j<c[0]) ans[i+j]='0';
                else ans[i+j]='1';
            }
            break;
        }
        c[idx]--;
        ans[i]=idx+'0';
        j++;
        if(j==m) j=pi[j-1];
    }
    printf("%s\n",ans);
    
    return 0;
}