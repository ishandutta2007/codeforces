#include<bits/stdc++.h>
using namespace std;
int n,m; 
int main()
{
	cin>>n>>m;
	if(n==1){
		if(m>2)cout<<"1\n"<<n<<" "<<m<<" 1 1\n";
		else cout<<"0\n";
		for(int i=1;i<=m;i++)
			cout<<"1 "<<i<<endl;
		cout<<"1 1",exit(0);
	}
	if(m==1){
		if(n>2)cout<<"1\n"<<n<<" "<<m<<" 1 1\n";
		else cout<<"0\n";
		for(int i=1;i<=n;i++)
			cout<<i<<" 1"<<endl;
		cout<<"1 1",exit(0);
	}
	if(n%2==0){
		cout<<"0\n";
		for(int i=1;i<=m;i++)
			cout<<"1 "<<i<<endl;
		for(int i=2;i<=n;i++)
			for(int j=2;j<=m;j++)
				cout<<i<<" "<<(i%2?j:m-j+2)<<endl;
		for(int i=n;i>0;i--)
			cout<<i<<" "<<1<<endl;
		exit(0);
	}
	if(m%2==0){
		cout<<"0\n";
		for(int i=1;i<=n;i++)
			cout<<i<<" 1"<<endl;
		for(int i=2;i<=m;i++)
			for(int j=2;j<=n;j++)
				cout<<(i%2?j:n-j+2)<<" "<<i<<endl;
		for(int i=m;i>0;i--)
			cout<<"1 "<<i<<endl;
		exit(0);
	}
	cout<<"1\n"<<n<<" "<<m<<" 1 1\n";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cout<<i<<" "<<(i%2?j:m-j+1)<<endl;
	cout<<"1 1";
    return 0;
}