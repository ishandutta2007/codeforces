#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[4],s; 
void dfs(int pos,int sum)
{
	if(pos==4){if(sum*2==s)cout<<"YES",exit(0);return;}
	dfs(pos+1,sum+a[pos]);
	dfs(pos+1,sum);
}
int main()
{
	for(int i=0;i<4;i++)
		cin>>a[i],s+=a[i];
	dfs(0,0);
	cout<<"NO";
    return 0;
}