#include <bits/stdc++.h>
using namespace std;
int n,k,m,a;
vector <int> c[100002]; 
int main()
{
	cin>>n>>k>>m;
	for(int i=0;i<n;i++)
		cin>>a,c[a%m].push_back(a);
	for(int i=0;i<m;i++)
		if(c[i].size()>=k){
			cout<<"Yes\n";
			for(int j=0;j<k;j++)
				cout<<c[i][j]<<" ";
			exit(0);
		}
	cout<<"No";
    return 0;
}