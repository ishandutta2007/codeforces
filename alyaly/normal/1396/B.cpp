#include<bits/stdc++.h>
#include<queue>
#define int long long
using namespace std;
int T,n,a[100001],ld,pl;
priority_queue<pair<int,int> > pq;
vector<pair<int,int> > ve;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;ld=0;pl=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		while(!pq.empty())pq.pop();
		for(int i=1;i<=n;i++)pq.push(make_pair(a[i],i));
		while(!pq.empty()){
			int np=pq.top().first,nd=pq.top().second;ve.clear();
			while(nd==ld&&!pq.empty())ve.push_back(make_pair(np,nd)),pq.pop(),np=pq.top().first,nd=pq.top().second;
			if(pq.empty())break;
			
			pq.pop();ld=nd;np--;a[nd]--;if(np)pq.push(make_pair(np,nd));
			for(int i=0;i<ve.size();i++)pq.push(make_pair(ve[i].first,ve[i].second));
			pl^=1;
		}
		if(pl==0)printf("HL\n");
		else printf("T\n");
	}
	return 0;
}