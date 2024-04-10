#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		if(n==1) printf("-1\n");
		else if(n==2) printf("57\n");
		else{
			for(int i=1;i<n;i++) printf("5");
			printf("8\n");
		}
	}
	return 0;
}