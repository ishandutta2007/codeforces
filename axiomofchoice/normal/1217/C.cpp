#include<bits/stdc++.h>
using namespace std;
const int N=200010;
char s[N];
int sum[N];
int is0(int l,int r){
    return sum[l-1]==sum[r];
}
void Solve(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(s[i]=='1');
    }
    int ans=0;
    for(int i=1;i<=n;i++)if(s[i]=='1'){
        int num=0;
        for(int j=i;j<=n;j++){
            num=num*2+(s[j]=='1');
            int left=j-num+1;
            if(left>=1 && is0(left,i-1))ans++;
            else break;
        }
    }
    printf("%d\n",ans);
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        Solve();
    }
    return 0;
}