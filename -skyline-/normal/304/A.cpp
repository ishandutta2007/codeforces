#include<iostream>
using namespace std;
bool s[100000005];
int n,i,j,k,c;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		s[i*i]=1;
	for(i=1;i<=n;i++){
		for(j=i;j<=n&&j*j+i*i<=n*n;j++){
			if(s[i*i+j*j])
				c++;
		}
	}
	cout<<c;
	//return 0;
}