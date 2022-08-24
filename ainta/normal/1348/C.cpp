#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K;
int C[26];
char p[101000];
void Solve(){
    int i, j;
    for(i=0;i<26;i++)C[i]=0;
    scanf("%d%d",&n,&K);
    scanf("%s",p);
    sort(p,p+n);
    for(i=0;i<n;i++)C[p[i]-'a']++;
    int x = p[0]-'a';
    if(C[x] < K){
        printf("%c\n",p[K-1]);
    }
    else if(p[K] == p[n-1]){
        for(i=0;i<n;i+=K)printf("%c",p[i]);
        puts("");
    }
    else{
        printf("%c",p[0]);
        for(i=K;i<n;i++)printf("%c",p[i]);
        puts("");
    }
}

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}