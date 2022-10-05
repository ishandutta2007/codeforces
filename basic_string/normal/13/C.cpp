#include<cstdio>
#include<queue>
using std::priority_queue;
priority_queue<int>q;
int main(){
	register int n,a;
	register long long s=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a),q.push(a);
		if(q.top()>a)s+=q.top()-a,q.pop(),q.push(a);
	}
	printf("%lld",s);
	return 0;
}