#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,poi,s,j[100005],del; 
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
		cin>>j[i],j[i]--;
	while(poi<m){
		s++;
		j[poi]-=del;
		while((++poi)<m&&(j[poi]-del)/k==j[poi-1]/k)
			j[poi]-=del;
		del=poi;
	}
	cout<<s;
    return 0;
}