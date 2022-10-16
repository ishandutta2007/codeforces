#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n ;
	cin>>n ;
	//int I,J;
	//vector<vector<int> > v(n,vector<int>(3,0));
	vector<int> v(n,0);
	
	for(int i=0; i<v.size() ; i++)
	{
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size() ; i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}