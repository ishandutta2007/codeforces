#include<bits/stdc++.h>
using namespace std;
int x[1010],y[1010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]+=1<<20;
		y[i]+=1<<20;
	}
	vector<int> v;
	bool flag=true;
	while(flag){
		flag=false;
		int c[4]={};
		for(int i=0;i<n;i++){
			c[(x[i]&1)*2+(y[i]&1)]++;
		}
		if(c[0]+c[3]>=1&&c[0]+c[3]<n){
			for(int i=0;i<n;i++){
				if((x[i]+y[i])&1) v.push_back(i+1);
			}
		}
		else if(c[0]<n&&c[1]<n&&c[2]<n&&c[3]<n){
			for(int i=0;i<n;i++){
				if(x[i]&1) v.push_back(i+1);
			}
		}
		else{
			flag=true;
			for(int i=0;i<n;i++){
				x[i]>>=1;
				y[i]>>=1;
			}
		}
	}
	printf("%d\n",(int) v.size());
	for(int i=0;i<v.size();i++){
		printf("%d%c",v[i],i<v.size()-1?' ':'\n');
	}
	return 0;
}