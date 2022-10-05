#include<iostream> 
using namespace std; 
const int maxn=1e6+1000;
int b[maxn],n,cnt;
int main(){ 
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=n-1,j=n;i>=0;i--){
		if(i<j)
			cnt++;
		j=min(i-b[i],j);
	}
	cout<<cnt;
	return 0; 
}