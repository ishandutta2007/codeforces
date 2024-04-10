#include<bits/stdc++.h>
using namespace std;
int n,x,y,a[100001];
deque<int>q;
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=y;i++){
		while(!q.empty()&&a[q.back()]>a[i])q.pop_back();
		q.push_back(i);
	}
	for(int i=y+1;i<=n;i++){
		while(!q.empty()&&i-q.front()>x+y+1)q.pop_front();
		while(!q.empty()&&a[q.back()]>a[i])q.pop_back();
		q.push_back(i);
		if(a[q.front()]>=a[i-y]){printf("%d\n",i-y);return 0;}
	}
	for(int i=n+1;i<=n+y;i++){
		while(!q.empty()&&i-q.front()>x+y+1)q.pop_front();
		if(a[q.front()]>=a[i-y]){printf("%d\n",i-y);return 0;}
	}
	return 0;
}