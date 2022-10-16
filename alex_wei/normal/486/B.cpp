#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,b[105][105],a[105][105]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>b[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int p1=1;
			for(int k=1;k<=n;k++)
				if(!b[k][j])
					p1=0;
			for(int k=1;k<=m;k++)
				if(!b[i][k])
					p1=0;
			a[i][j]=p1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int p1=0;
			for(int k=1;k<=n;k++)
				p1|=a[k][j];
			for(int k=1;k<=m;k++)
				p1|=a[i][k];
			if(p1!=b[i][j])puts("NO"),exit(0);
		}
	puts("YES");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
    return 0;
}