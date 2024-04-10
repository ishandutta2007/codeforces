#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
#define f(a,b,c,d) (sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1])
using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	string s;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<vector<int> > a,sum;
		sum.resize(n+1);
		a.resize(n+1);
		for(int i=0;i<=n;i++){
			a[i].resize(m+1);
			sum[i].resize(m+1);
		}
		for(int i=1;i<=n;i++){
			cin >> s;
			for(int j=1;j<=m;j++){
				a[i][j]=s[j-1]-'0';
				sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
			}
		}
		int mx=16;
		for(int i=1;i<=n-4;i++){
			for(int j=1;j<=m-3;j++){
				int no=n,mo=m;
				for(int k=i+4;k<=no;k++){
					for(int l=j+3;l<=mo;l++){
						int in=f(i+1,j+1,k-1,l-1);
						int ls=l-j-1-f(i,j+1,i,l-1);
						int rs=l-j-1-f(k,j+1,k,l-1);
						int us=k-i-1-f(i+1,j,k-1,j);
						int ds=k-i-1-f(i+1,l,k-1,l);
						//cout << in << ls << rs << us << ds << endl;
						mx=min(mx,in+ls+rs+us+ds);
						if(in>=16){
							mo=l;
						}
						if(ls>=16){
							no=k;
						}
						if(us>=16){
							mo=l;
						}
					}
				}
			}
		}
		cout << mx << "\n";
	}
	return 0;
}