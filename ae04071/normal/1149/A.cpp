#include <bits/stdc++.h>
using namespace std;

int a[2],n;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int v;
        scanf("%d",&v);
        a[v-1]++;
    }
    
    if(a[1]) {
        printf("2 ");a[1]--;
        if(a[0]) printf("1 "),a[0]--;
        while(a[1]--) printf("2 ");
        while(a[0]--) printf("1 ");
    } else {
        while(a[0]--) printf("1 ");
    }
    
    return 0;
}