#include<cstdio>
#include<utility>
#include<queue>
using namespace std;
int main(){
	int n,m,i,a[101]={0},x;
	priority_queue<pair<int,int> > pq;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	for(i=1;i<=100;i++){
		if(a[i]) pq.push(make_pair(a[i],i));
	}
	if(pq.top().first<=n-pq.top().first){
		printf("%d\n",n);
	}
	else{
		printf("%d\n",2*(n-pq.top().first));
		pair<int,int> fst=pq.top();
		pq.pop();
		for(i=0;i<fst.first*2-n;i++) printf("%d %d\n",fst.second,fst.second);
		if(n-fst.first>0) pq.push(make_pair(n-fst.first,fst.second));
	}
	while(!pq.empty()){
		pair<int,int> fst=pq.top(),snd;
		pq.pop();
		snd=pq.top();
		pq.pop();
		if(n==3){
			pair<int,int> trd=pq.top();
			pq.pop();
			printf("%d %d\n",fst.second,snd.second);
			printf("%d %d\n",snd.second,trd.second);
			printf("%d %d\n",trd.second,fst.second);
		}
		else{
			printf("%d %d\n",fst.second,snd.second);
			printf("%d %d\n",snd.second,fst.second);
			if(fst.first>1) pq.push(make_pair(fst.first-1,fst.second));
			if(snd.first>1) pq.push(make_pair(snd.first-1,snd.second));
			n-=2;
		}
	}
	return 0;
}