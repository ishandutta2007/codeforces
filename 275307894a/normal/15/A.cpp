#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
struct yyy{
    int x;
    double y;
}s[1001];
bool cmp(yyy a,yyy b){
    return a.x<b.x;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%lf",&s[i].x,&s[i].y),s[i].y/=2;
    sort(s+1,s+n+1,cmp);
    for(int i=2;i<=n;i++){
        if(s[i].x-s[i-1].x-s[i-1].y-s[i].y>m) ans++;
        if(s[i].x-s[i-1].x-s[i-1].y-s[i].y>=m) ans++;
    }
    printf("%d",ans+2);
    return 0;
}