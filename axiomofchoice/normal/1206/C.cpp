#include<bits/stdc++.h>
using namespace std;
int n,N,a[200010],p,flag;
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n; N=2*n;
	if(n%2==1){
		p=0;
		flag=true;
		for(int i=1;i<=N;i++){
			a[p]=i;
			if(flag)p=(p+n)%N;
			else p--;
			flag^=1;
		}
		cout<<"YES"<<endl;
		for(int i=0;i<N;i++)cout<<a[i]<<' ';
		cout<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}