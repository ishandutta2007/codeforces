#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int M=100005;
int a[M],t,n,m;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%d",a+i);
        sort(a+1,a+m+1);
        int ans=n,day=0;
        priority_queue<int> pq;
        for(int i=1;i<=m;i++)
            pq.push((a[i%m+1]-a[i]+n)%n-1);
        if(m==1) pq.push(n-1);
        while(!pq.empty()){
            int tmp=pq.top(); pq.pop();
            tmp-=2*day;
            if(tmp<=0) break;
            if(tmp<=2) {day+=1,--ans; break;} 
            day+=2;
            ans-=tmp-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}