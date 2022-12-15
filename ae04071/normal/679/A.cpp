#include <bits/stdc++.h>
using namespace std;

int vis[101];
int main() {
    int c=0;
    vector<int> prime;
    for(int i=2;i<=100;i++) if(!vis[i]) {
        if(i<=50) c++;
        prime.push_back(i);
        for(int j=i*i;j<=100;j+=i) vis[j]=1;
    }

    int cnt=0;
    char str[10];
    for(int i=0;i<15;i++) {
        printf("%d\n",prime[i]);
        fflush(stdout);
        scanf("%s",str);
        if(str[0]=='y') cnt++;
    }
    if(cnt==0) puts("prime");
    else if(cnt>=2) puts("composite");
    else {
        for(int i=0;i<4;i++) {
            printf("%d\n",prime[i]*prime[i]);
            fflush(stdout);
            scanf("%s",str);
            if(str[0]=='y') cnt++;
        }
        if(cnt>=2) puts("composite");
        else puts("prime");
    }
    fflush(stdout);
    
    return 0;
}