#include<bits/stdc++.h>
#define N 300100
using namespace std;
int a[N];
int ed[N];
list<int> q[N];
int ans[N];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		ed[i]=-1;
	}
	m=n*3;
	for(int i=n;i<m;i++){
		a[i]=a[i%n];
		ed[i]=-1;
	}
	vector<int> stk;
	for(int i=m-1;i>=0;i--){
		q[i].push_back(i);
		while(!stk.empty()&&a[i]>=a[stk.back()]){
			int b=stk.back();
			stk.pop_back();
			if(ed[i]<0){
				while(!q[b].empty()&&a[q[b].front()]>=a[q[i].back()]) q[b].pop_front();
				q[i].splice(q[i].end(),q[b]);
				ed[i]=ed[b];
			}
		}
		bool flag=false;
		while(!q[i].empty()){
			if(a[q[i].back()]<(a[i]+1)/2){
				ed[i]=q[i].back();
				q[i].pop_back();
			}
			else break;
		}
		if(ed[i]>=0) ans[i]=ed[i];
		else if(stk.empty()) ans[i]=m;
		else ans[i]=ans[stk.back()];
		stk.push_back(i);
	}
	for(int i=0;i<n;i++){
		if(i) putchar(' ');
		if(ans[i]==m) printf("-1"); 
		else printf("%d",ans[i]-i);
	}
	puts("");
	return 0;
}