#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int n,cnt,pr[N],p[N]; 
int main(){
	for(int i=2;i<N;i++){
		if(!p[i]){
			pr[++cnt]=i;
			for(int j=i<<1;j<N;j+=i)p[j]=1;
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++)cout<<pr[i]<<" ";
	return 0;
}