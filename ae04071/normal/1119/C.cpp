#include <bits/stdc++.h>
using namespace std;

int n,m,A[500][500],B[500][500];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&A[i][j]);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&B[i][j]);

    for(int i=0;i<n;i++) {
        int a=0,b=0;
        for(int j=0;j<m;j++) a^=A[i][j],b^=B[i][j];
        if(a!=b) {
            puts("No");
            return 0;
        }
    }
    for(int j=0;j<m;j++) {
        int a=0,b=0;
        for(int i=0;i<n;i++) a^=A[i][j],b^=B[i][j];
        if(a!=b) {
            puts("No");
            return 0;
        }

    }
    puts("Yes");
    
    return 0;
}