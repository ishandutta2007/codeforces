#include <bits/stdc++.h>
using namespace std;

int n;
char str[201];

bool check(int a,int b,int c) {
    if((a&&b) || (!a&&!b) || (c && (a>=2 || b>=2))) return true;
    else return false;
}
int main() {
    int r=0,g=0,b=0;
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=0;i<n;i++) {
        if(str[i]=='R') r++;
        else if(str[i]=='G') g++;
        else b++;
    }
    if(check(r,g,b)) printf("B");
    if(check(r,b,g)) printf("G");
    if(check(b,g,r)) printf("R");

    return 0;
}