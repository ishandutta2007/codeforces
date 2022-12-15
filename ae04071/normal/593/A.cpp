#include <bits/stdc++.h>
using namespace std;

int n;
char str[100][1010];
int sl[100],cnt[100][26];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    for(int i=0;i<n;i++) {
        sl[i] = strlen(str[i]);
        for(int j=0;j<sl[i];j++) {
            cnt[i][str[i][j]-'a']++;
        }
    }

    int mx=0;
    for(int a=0;a<26;a++) for(int b=a+1;b<26;b++) {
        int l=0;
        for(int i=0;i<n;i++) {
            if(sl[i] == cnt[i][a] + cnt[i][b]) l+=sl[i];
        }
        mx = max(mx,l);
    }
    printf("%d\n",mx);

    return 0;
}