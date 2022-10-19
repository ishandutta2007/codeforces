#include<bits/stdc++.h>
using namespace std;
int n,T;
priority_queue<int>q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int x;n--;)scanf("%d",&x),q.push(x);
		int las=0,now=1;
		while(!q.empty()){
			int x=q.top();q.pop();
			now^=1;
			if(las)q.push(las);
			las=x-1;
		}
		puts(now?"HL":"T");
	}
	return 0;
}