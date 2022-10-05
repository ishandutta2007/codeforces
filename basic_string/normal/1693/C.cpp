#include<bits/stdc++.h>
using namespace std;
const int N=200009;
basic_string<int>g[N];
int d[N],out[N];
priority_queue<pair<int,int>>q;
bool v[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,j,k,n,m;
	cin>>n>>m;
	memset(d,9,sizeof d),d[n]=0,q.push({0,n});
	while(m--)cin>>i>>j,g[j]+=i,++out[i];
	while(q.size()){
		i=q.top().second;q.pop(); 
		if(v[i])continue;
		v[i]=1;
		for(int j:g[i]){
			if(d[j]>d[i]+out[j]){
				d[j]=d[i]+out[j];
				q.push({-d[j],j});
			}
			--out[j];
		}
	}
	cout<<d[1];
}