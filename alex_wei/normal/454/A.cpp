#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			abs(i-(n/2+1))+abs(j-(n/2+1))>n/2?cout<<'*':cout<<"D";
		cout<<endl;
	}
	return 0;
}