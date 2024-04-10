#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N],b[N];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int t=0;
		int st=0,ed=0,bd=0,ng=0;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		for(int i=0;i<n;i++){
			if(b[i]<a[i]) ng++;
			if(b[i]-a[i]!=t){
				if(!t) st++;
				else if(b[i]==a[i]) ed++;
				else bd++;
				t=b[i]-a[i];
			}
		}
		if(st<=1&&ed<=1&&bd<=0&&ng<=0){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}