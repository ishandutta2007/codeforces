#include<bits/stdc++.h>
using namespace std;
int n,m;
char c; 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>c;
			if(c=='C'||c=='M'||c=='Y')cout<<"#Color",exit(0);
		}
	cout<<"#Black&White";
    return 0;
}