#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

char s[100100],t[100100];
int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%s%s",s,t);
        
        int n=strlen(s),m=strlen(t);
        int i=n-1,j=m-1;
        for(;j>=0 && t[j]=='0';j--);
        for(i=n-(m-j);i>=0 && s[i]=='0';i--);
        printf("%d\n",max(0, (n-i)-(m-j)));
    }
    return 0;
}