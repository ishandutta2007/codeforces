#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
for(int i=(a),i##end=(b);i<i##end;i++)
int n;
ll a[1010][1010];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	repeat(i,0,n)
	repeat(j,0,n)
		cin>>a[i][j];
	repeat(i,0,n){
		int j=(i+1)%n;
		int k=(j+1)%n;
		int ans=int(
		sqrt(a[i][j]*a[i][k]/a[j][k])
		+0.5);
		cout<<ans<<' ';
	}
	cout<<endl;
	return 0;
}