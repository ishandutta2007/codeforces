#include<bits/stdc++.h>
using namespace std;
int T;
char c[43][43];
int main(){
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		if((n+1)/2<k){
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				c[i][j]='.';
		int x=0;
		while(k--){
			c[x][x]='R';x+=2;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				putchar(c[i][j]);
			cout<<endl;
		}
	}
}