#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define maxn 300300

int v[maxn];
int pos[maxn];

#define pii pair<int,int>
vector<pii> ans;

void sw(int a,int b){
//	printf("oi %d %d\n",a,b);
	swap(pos[v[a]],pos[v[b]]);
	swap(v[a],v[b]);
	ans.pb(pii(a,b));
}

int main(){

	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",v+i), v[i]--;
		pos[v[i]] = i;
	}
	
	for(int i=1;i<n-1;i++){
	
		if(pos[i] < n/2){
			sw(pos[i],n-1);
			if(i < n/2)
				sw(i,n-1);
			else {
				sw(0,n-1);
				sw(0,i);	
			}
		}
		
		else {
			sw(pos[i],0);
			if(i >= n/2)
				sw(0,i);
			else {
				sw(0,n-1);
				sw(n-1,i);
			}
		}
	
	}
	
	//for(int i=0;i<n;i++)
	//	printf("pos(%d) = %d\n",i,pos[i]);
		
	if(pos[0] != 0)
		sw(0,n-1);
		
	printf("%d\n",ans.size());
	
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].first+1,ans[i].second+1);

}