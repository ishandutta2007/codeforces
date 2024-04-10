#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,m,y;
	long long rm=0;
	scanf("%d%d%d",&n,&k,&m);
	vector<int> x,c;
	for(int i=0;i<n;i++){
		scanf("%d",&y);
		if(!x.empty()&&x.back()==y){
			c.back()++;
		}
		else{
			x.push_back(y);
			c.push_back(1);
		}
		if(!c.empty()&&c.back()==k){
			c.pop_back();
			x.pop_back();
		}
	}
	for(int i=0;i<c.size()-1-i;i++){
		if(x[i]!=x[x.size()-1-i]) break;
		if(c[i]+c[c.size()-1-i]>=k){
			//puts("!!");
			c[i]-=k-c[c.size()-1-i];
			c[c.size()-1-i]=0;
			rm+=k;
		}
		if(c[i]){
			break;
		}
	}
	if(c.size()%2 && (c.size()==1 || c[c.size()/2-1]==0)){
		long long trm=c[c.size()/2];
		if(trm*m%k==0) rm=0;
		else rm+=trm*m%k;
		c[c.size()/2]=0;
	}
	for(int i=0;i<c.size();i++){
		rm+=1LL*c[i]*m;
		//printf("%d\n",c[i]);
	}
	printf("%I64d\n",rm);
	return 0;
}