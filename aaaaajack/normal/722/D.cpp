#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	set<int> y;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		y.insert(x);
	}
	while(1){
		int now=*y.rbegin();
		while(now&&y.count(now)) now>>=1;
		if(!now) break;
		y.erase(--y.end());
		y.insert(now);
	}
	for(auto it=y.begin();it!=y.end();++it){
		printf("%d ",*it);
	}
	return 0;
}