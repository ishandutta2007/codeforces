#include <bits/stdc++.h>
using namespace std;

int n;
char s[200100],a[200100],b[200100];

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%s",&n,s);

        int zc=0;
        for(int i=0;i<n;i++) {
            s[i] -= '0';
            if(!s[i]) zc++;
        }

        if(zc&1) {
            puts("NO");
            continue;
        }
        bool f=true;
        int cc=zc/2, cf=0, st=0;
        for(int i=0;i<n;i++) {
            if(s[i]) {
                if (cc == n/2) {
                    a[i] = b[i] =')';
                    st--;
                }
                else {
                    a[i] = b[i] = '(';
                    cc++;
                    st++;
                }
            } else {
                if(!cf) {
                    a[i] ='(';
                    b[i] =')';
                    st--;
                } else {
                    a[i] =')';
                    b[i] ='(';
                    st++;
                }
                cf ^= 1;
            }
            if(st < 0) {
                f = false;
                break;
            }
        }
        puts(f ? "YES" : "NO");
        if(f) {
            a[n] = b[n] = 0;
            printf("%s\n%s\n",a,b);
        }
    }
    return 0;
}