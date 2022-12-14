#include<bits/stdc++.h>
using namespace std;
int n,ans,m;
int len[110][110];
int a[1000010];
string s;
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<n;j++)
		if(s[j]=='1')len[i][j]=1;
		else if(i==j)len[i][j]=0;
		else len[i][j]=1<<29;
	}
	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
	cin>>m;
	ans=0;
	for(int i=0;i<m;i++){
		cin>>a[i];a[i]--;
		if(i>=2){
			if(len[a[i-2]][a[i-1]]+len[a[i-1]][a[i]]==
			len[a[i-2]][a[i]])
				a[i-1]=a[i],i--,m--;
		}
	}
	cout<<m<<endl;
	for(int i=0;i<m;i++)
		cout<<a[i]+1<<' ';
	cout<<endl;
	return 0;
}