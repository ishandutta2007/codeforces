#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
int a[20000],b[20000];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int sum=0;
	repeat(i,0,n){
		cin>>a[i];
		b[i]=(a[i]%2);
		if(a[i]<0 && b[i])a[i]/=2,a[i]--;
		else a[i]/=2;
		sum+=a[i];
	}
	sum=-sum;
	repeat(i,0,n){
		if(sum>0 && b[i])cout<<a[i]+1<<endl,sum--;
		else cout<<a[i]<<endl;
	}
	return 0;
}