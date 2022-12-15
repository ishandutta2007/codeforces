#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[200100],t[200100];

int ps[200100][26],cnt[26];

int main() {
    int test;
    scanf("%d%s%d",&n,s+1,&test);
    for(int i=1;i<=n;i++) {
        for(int j=0;j<26;j++) ps[i][j] = ps[i-1][j];
        ps[i][s[i]-'a']++;
    }

    while(test--) {
        scanf("%s",t);
        m=strlen(t);

        for(int i=0;i<26;i++) cnt[i]=0;
        for(int i=0;i<m;i++) cnt[t[i]-'a']++;
        
        int lo=0,up=n;
        while(up-lo>1) {
            int md=(lo+up)>>1,f=1;
            for(int j=0;j<26;j++) if(cnt[j] > ps[md][j]) {
                f=0;
                break;
            }
            if(f) up=md;
            else lo=md;
        }
        printf("%d\n",up);
    }
    return 0;
}