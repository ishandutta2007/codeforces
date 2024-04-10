#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,a[100039],tots[100039],s[100039],ans,g[4],tot;
struct yyy{
    int num,ans;
    bool operator<(const yyy &x) const {
        return ans< x.ans;
    }
}tmp,now1,now2,now3;
priority_queue<yyy> q;
int main(){
//  freopen("snow.in","r",stdin);
//  freopen("snow.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++) {
    	for(j=i+1;j<=n;j++) if(a[j]!=a[j-1]) break;
    	j--;
    	q.push((yyy){a[i],j-i+1});
    	i=j;
	}
    while(q.size()>=3){
        ans++;
        now1=q.top();q.pop();
        now2=q.top();q.pop();
        now3=q.top();q.pop();
        now1.ans--;now2.ans--;now3.ans--;
        if(now1.ans) q.push(now1);
        if(now2.ans) q.push(now2);
        if(now3.ans) q.push(now3);
    }
    while(!q.empty())q.pop();
    printf("%d\n",ans);
    for(i=1;i<=n;i++) {
    	for(j=i+1;j<=n;j++) if(a[j]!=a[j-1]) break;
    	j--;
    	q.push((yyy){a[i],j-i+1});
    	i=j;
	}
    while(q.size()>=3){
        now1=q.top();q.pop();
        now2=q.top();q.pop();
        now3=q.top();q.pop();
        now1.ans--;now2.ans--;now3.ans--;
        g[1]=now1.num,g[2]=now2.num,g[3]=now3.num;
        sort(g+1,g+4);
        printf("%d %d %d\n",g[3],g[2],g[1]);
        if(now1.ans) q.push(now1);
        if(now2.ans) q.push(now2);
        if(now3.ans) q.push(now3);
    }
}