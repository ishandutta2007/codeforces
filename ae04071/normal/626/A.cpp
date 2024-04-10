#include <bits/stdc++.h>
using namespace std;

const int dy[]={-1,1,0,0},dx[]={0,0,-1,1};
int get(char ch) {
    if(ch=='U') return 0;
    else if(ch=='D') return 1;
    else if(ch=='L') return 2;
    else return 3;
}

char str[201];
int n;

int main() {
    int ans=0;
    scanf("%d%s",&n,str);
    for(int l=0;l<n;l++) for(int r=l;r<n;r++) {
        int y=0,x=0,idx;
        for(int k=l;k<=r;k++) {
            idx=get(str[k]);
            y+=dy[idx]; x+=dx[idx];
        }
        if(y==0 && x==0) ans++;
    }
    printf("%d\n",ans);
    return 0;
}