#include <iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	if(k>=n)      {
		cout<<n;
		return 0;}
	else{
		for(int i=1;i<=k;i++){
			if(a[i]>a[0])
				break;
			if(i==k){
				cout<<a[0];
				return 0;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i;j<min(n,i+k);j++){
				if(a[j]>a[i]){
					i=j-1;
					break;
				}
				if(j==min(n,i+k)-1){
					cout<<a[i];
					return 0;
				}
			}
		}
	}
	cout<<n;
}