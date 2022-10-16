#include<bits/stdc++.h>
using namespace std;
int n;
string a,b[102];
int main()
{
	cin>>a>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(b[i]==a)cout<<"YES",exit(0);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(b[i][1]==a[0]&&b[j][0]==a[1])
				cout<<"YES",exit(0);
	cout<<"NO";
	return 0;
}