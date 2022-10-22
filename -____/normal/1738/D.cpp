#include<bits/stdc++.h>
using namespace std;
const int N = 111111;
int n,a[N],b[N];
vector<int> v[N];
priority_queue<pair<int,int> > q;
int main(){
	int T,i,x,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s=0;
		x=0;
		for(i=1;i<=n;i++){
			scanf("%d",b+i);
			if(b[i]>i)
				x=i;
			v[b[i]].push_back(i);
		}
		printf("%d\n",x);
		q.push(make_pair(-v[0].size(),0));
		q.push(make_pair(-v[n+1].size(),n+1));
		s=0;
		while(!q.empty()){
			x=q.top().second;
			q.pop();
			a[++s]=x;
			for(i=0;i<v[x].size();i++)
				q.push(make_pair(-v[v[x][i]].size(),v[x][i]));
		}
		for(i=3;i<=n+2;i++)
			printf("%d ",a[i]);
		printf("\n");
		for(i=0;i<=n+1;i++)
			v[i].clear();
	}
	return 0;
}