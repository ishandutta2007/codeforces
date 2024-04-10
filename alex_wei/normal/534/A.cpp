#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	if(n==1)cout<<"1\n1";
	else if(n==2)cout<<"1\n1";
	else if(n==3)cout<<"2\n1 3";
	else{
		cout<<n<<endl;
		if(n%4)cout<<"1 ";
		if(n%4==3)cout<<"3 ";
		for(int i=n;i>n%4;i-=4)
			cout<<i-2<<" "<<i<<" "<<i-3<<" "<<i-1<<" ";
		if(n%4>1)cout<<"2 ";
	}
	return 0;
}