#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 555;
int n,b[N],a[N][N];
int main(){
	int T,i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>b[i];
	for(i=1;i<=n;i++){
		k=1;
		for(j=1;j<=n;j++)
			if(b[j]>=i)
				a[i-1+k][k]=b[j],k++;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}