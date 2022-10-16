#include<bits/stdc++.h>
using namespace std;
const int N=3;
int c[N][N];
int main(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)cin>>c[i][j];
	}
	for(int i=1;i<=1e5;i++){
		int sum=c[1][0]+i+c[1][2];
		int a1=sum-c[0][1]-c[0][2];
		int a2=sum-c[2][0]-c[2][1];
		if(a1+a2+i==sum&&a1+c[1][0]+c[2][0]==sum&&c[0][2]+c[1][2]+a2==sum){
			c[0][0]=a1;
			c[1][1]=i;
			c[2][2]=a2;
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++)cout<<c[j][k]<<" ";
				puts("");
				
			}
			exit(0);
		}
	}
	return 0;
}