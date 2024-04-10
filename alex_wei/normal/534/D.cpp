#include<bits/stdc++.h>
using namespace std;
int n,a[200002],ans[200002],cnt,pos;
deque <int> g[200002];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],g[a[i]].push_back(i);
	while(cnt<n){
		if(g[pos].size()){
			ans[++cnt]=g[pos].front(),g[pos].pop_front();
			pos++;
		}
		else{
			if(pos<3)cout<<"Impossible",exit(0);
			pos-=3;
		}
	}
	puts("Possible");
	for(int i=1;i<=cnt;i++)
		cout<<ans[i]<<" ";
	return 0;
}