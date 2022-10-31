#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
vector<pair<long long,long long > > ans; 
int main(){
	long long x,y;
	scanf("%I64d",&x);
	x*=6;
	for(long long i=1;i<=1500000;i++){
		if(x%i==0){
			y=x/i;
			if(y%(i+1)==0){
				y/=i+1;
				if((y+i-1)%3==0){
					long long j=(y+i-1)/3;
					if(j>=i) ans.push_back(make_pair(i,j));
				}
			}
		}
	}
	for(int i=ans.size()-1;i>=0;i--){
		if(ans[i].F!=ans[i].S) ans.push_back(make_pair(ans[i].S,ans[i].F));
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%I64d %I64d\n",ans[i].F,ans[i].S);
	}
	return 0;
}