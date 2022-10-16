#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+5;
int n,ans,buc[N];
char a[N][N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++){
		memset(buc,0,sizeof(buc));
		for(int j=1;j<=n;j++){
			int rev=a[i][j]!='0';
			for(int k=1;k<=n;k++)buc[k]+=a[k][j]^48^rev^1;
		}
		int cnt=0;
		for(int j=1;j<=n;j++)cnt+=buc[j]==n;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
    return 0;
}