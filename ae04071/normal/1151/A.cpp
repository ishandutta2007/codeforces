#include <bits/stdc++.h>
using namespace std;

int get(int l,int r){
    if(l<=r) return r-l;
    else return 26-l+r;
}
char str[100];
int n,cost[26],v[4]={0,2,19,6};

int main() {
    scanf("%d",&n);
    scanf("%s",str);
    
    for(int i=0;i<26;i++) {
        cost[i] = 26;
        for(int j=0;j<4;j++) cost[i] = min(cost[i],min(get(i,v[j]),get(v[j],i)));
    }
    
    int ans=300;
    for(int i=0;i<=n-4;i++) {
        int c=0;
        for(int j=0;j<4;j++) {
            int t=str[i+j]-'A';
            c += min(get(t,v[j]),get(v[j],t));
        }
        ans =min(ans,c);
    }
    printf("%d\n",ans);
    
    return 0;
}