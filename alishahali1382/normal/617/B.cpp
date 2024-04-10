#include <iostream>

using namespace std;

int main(){
	int n,flag=0,ai,count=0;
	long long out=1;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>ai;
		if (flag){
			if (ai==0){
				count++;
			}
			else{
				out*=count+1;
				count=0;
			}
		}
		flag=ai|flag;
	}
	if (flag)
		cout<<out<<endl;
	else
		cout<<0<<endl;
}