#include<bits/stdc++.h>
using namespace std;
int main(){
	deque<long long> q;
	int n,b;
	int t,x;
	scanf("%d%d",&n,&b);
	while(n--){
		scanf("%d%d",&t,&x);
		while(!q.empty()&&q.front()<=t) q.pop_front();
		if(q.size()>b) printf("-1 ");
		else if(q.empty()){
			printf("%d ",t+x);
			q.push_back(t+x);
		}
		else{
			printf("%I64d ",q.back()+x);
			q.push_back(q.back()+x);
		}
	}
	puts("");
	return 0;
}