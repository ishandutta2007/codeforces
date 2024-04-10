#include <bits/stdc++.h>
using namespace std;
int ans[101][2];
int st[2];
int rans[101];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("?");
        for(int j=1;j<=n;j++) printf(" %d",(i==j?1:2));
        puts("");
        fflush(stdout);
        int tmp;
        scanf("%d",&tmp);
        if(tmp==0){ // it's 1
            st[0] = i;
        }
        else if(tmp!=i){ // v[tmp]+2 = v[i]+1
            ans[i][0] = tmp;
            ans[tmp][1] = i;
        }
        printf("?");
        for(int j=1;j<=n;j++) printf(" %d",(i==j?2:1));
        puts("");
        fflush(stdout);
        scanf("%d",&tmp);
        if(tmp==0){ // it's n
            st[1] = i;
        }
        else if(tmp!=i){ // v[tmp]+1 = v[i]+2
            ans[i][1] = tmp;
            ans[tmp][0] = i;
        }
    }
    for(int i=1;i<=n;i++){
        rans[st[0]] = i;
        st[0] = ans[st[0]][1];
    }
    printf("!");
    for(int i=1;i<=n;i++) printf(" %d",rans[i]);
    puts("");
    fflush(stdout);
}