#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n;
vector<int>v[310];
priority_queue<pii,vector<pii>,greater<pii> >q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)q.push(make_pair(0,i));
	for(int i=n*n;i;i--){
		pii p=q.top();q.pop();
		v[p.second].push_back(i),p.first+=i;
		q.push(p);
	}
	for(int i=1;i<=n;i++){for(int j=0;j<n;j++)printf("%d ",v[i][j]);puts("");}
	return 0;
}