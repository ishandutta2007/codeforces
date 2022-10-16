#include<bits/stdc++.h>
using namespace std;
int k,d;
int main()
{
	cin>>k>>d;
	if(d==0&&k>1)cout<<"No solution";
	else{
		cout<<d;
		for(int i=1;i<k;i++)
			cout<<0;
	}
	return 0;
}