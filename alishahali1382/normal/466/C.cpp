#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int L[n];
	long long sum=0;
	for (int i=0;i<n;i++){
		cin>>L[i];
		sum+=L[i];
	}
	//cout<<sum<<endl;
	long long s=0;
	long long c3=0,c36=0,out=0;
	long long k=sum/3;
	long long t=0;
	if (sum%3!=0){
		cout<<0<<endl;
	}
	else if (sum!=0){
		for (int i=0;i<n;i++){
			s+=L[i];
			int a=0;
			if (s==k){
				a++;
			}
			else if (s==2*k){
				out+=c3;
			}
			c3+=a;
		}
		cout<<out<<endl;
	}
	else{
		
		for (int i=0;i<n;i++){
			s+=L[i];
			if (s==0){
				t++;
			}
		}
		cout<<(long long) ((t-1)*(t-2))/2<<endl;
	}/*
	if (n==500000){
		cout<<sum<<endl;
		cout<<t<<endl;
		cout<<c3<<' '<<c36<<' '<<endl;
		
	}*/
	
	return 0;	
}