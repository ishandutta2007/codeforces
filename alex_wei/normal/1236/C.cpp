#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector <int> ans[305];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			ans[j].push_back((i-1)*n+(i%2?j:n-j+1));
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
    return 0;
}