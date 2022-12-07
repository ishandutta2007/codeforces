#include<bits/stdc++.h>
using namespace std;
int T,nxt[10][500003],n,x;
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>s>>x;
		n=s.size();
		for(int i=0;i<10;i++)
			nxt[i][n]=n;
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<10;j++)
				nxt[j][i]=nxt[j][i+1];
			nxt[s[i]-'0'][i]=i;
		}
		int nw=0;
		for(int i=0;i<n-x;i++){
			int c=-1; 
			for(int j=9;j>=(!i);j--)
				if(n-nxt[j][nw]>=n-x-i)
					c=j;
			nw=nxt[c][nw]+1;
			cout<<c;
		}
		cout<<'\n';
	}
}