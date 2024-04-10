/* in the name of Anton */
#include<bits/stdc++.h>
#define N 200010
#define all(x) begin(x),end(x)
using namespace std;
int a[N],b[N],c[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		set<int> s;
		priority_queue<pair<int,int>> pq;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[a[i]]=i;
			s.insert(i);
			c[i]=1;
			pq.push(make_pair(1,i));
		}
		bool gg=false;
		for(int i=1;i<=n;i++){
			while(!pq.empty()){
				auto tmp=pq.top();
				int x=tmp.first,y=tmp.second;
				if(c[y]!=x || !s.count(y)) pq.pop();
				else break;
			}
			if(pq.empty() || pq.top().first > c[b[i]]){
				gg=true;
				break;
			}
			s.erase(b[i]);
			auto nxt=s.upper_bound(b[i]);
			if(nxt!=s.end()){
				c[*nxt]+=c[b[i]];
				pq.push(make_pair(c[*nxt],*nxt));
			}
		}
		if(gg) puts("No");
		else puts("Yes");
	}
	return 0;
}