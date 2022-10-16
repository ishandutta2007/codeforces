#include<bits/stdc++.h>
using namespace std;
int t[102][102],n,m,dis[102][102];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>t[i][j];
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			int pd=1;
			for(int k=1;k<=m;k++)
				if(t[i][k]!=t[j][k])
					pd=0;
			dis[i][j]=dis[j][i]=pd;
		}
	int siz=n;
	while(!(siz%2)){
		int m=siz>>1,pd=1;
		while(m<n){
			for(int pos=m+1;pos<=m<<1;pos++)
				if(!dis[m*2+1-pos][pos])
					pd=0;
			if(!pd)break;
			m<<=1;
		}
		if(!pd)break;
		siz>>=1;
	}
	cout<<siz<<endl;
	return 0;
}