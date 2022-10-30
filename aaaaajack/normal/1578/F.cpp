#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int s[30]={};
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			for(int r=0;r<30;r++){
				if(x&(1<<r)) s[r]++;
			}
		}
		for(int i=1;i<=n;i++){
			bool good=true;
			for(int j=0;j<30;j++){
				if(s[j]%i) good=false;
			}
			if(good) printf("%d ",i);
		}
		puts("");
	}
	return 0;
}