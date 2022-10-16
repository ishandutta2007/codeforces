#include<bits/stdc++.h>
using namespace std;
int n,k;
char ans[102][102];
int main()
{
	cin>>n>>k;
	if(k>(n*n-1)/2+1)puts("NO"),exit(0);
	puts("YES");
	for(int i=1;i<=n;i++)
		for(int j=(i%2?1:n);(i%2?j<=n:j>=1);j+=(i%2?1:-1))
			if((i+j)%2==0&&k)ans[i][j]='L',k--;
			else ans[i][j]='S';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<ans[i][j];
		cout<<endl; 
	}
    return 0;
}