#include<bits/stdc++.h>
using namespace std;
string a,b[5];
int main()
{
	cin>>a;
	for(int i=0;i<5;i++){
		cin>>b[i];
		if(b[i][0]==a[0]||b[i][1]==a[1])cout<<"YES",exit(0);
	}
	cout<<"NO";
	return 0;
}