#include<bits/stdc++.h>
#define N 1100
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x;
		scanf("%d",&n);
		vector<int> v;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x==1){
				for(int j=0;j<v.size();j++) printf("%d.",v[j]);
				puts("1");
				v.push_back(1);
			}
			else{
				while(v.back()!=x-1) v.pop_back();
				v.back()++;
				for(int j=0;j+1<v.size();j++) printf("%d.",v[j]);
				printf("%d\n",v.back());
			}
		}
	}
	return 0;
}