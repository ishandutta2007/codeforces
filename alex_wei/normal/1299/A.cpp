#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1E5+5;
int n,a[N],ans,buc[32];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<31;j++)if((a[i]>>j)&1)buc[j]++;
	}
	for(int j=30;j>=0;j--){
		if(buc[j]==1){
			for(int i=1;i<=n;i++){
				if((a[i]>>j)&1){
					cout<<a[i]<<" ";
					for(int j=1;j<i;j++)cout<<a[j]<<" ";
					for(int j=i+1;j<=n;j++)cout<<a[j]<<" ";
					exit(0); 
				}
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}