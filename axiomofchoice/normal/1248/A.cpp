#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>

ll t,n,x,a[2],b[2];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>t;
	while(t--){
		mst(a,0),mst(b,0);
		cin>>n;
		while(n--){cin>>x;a[x%2]++;}
		cin>>n;
		while(n--){cin>>x;b[x%2]++;}
		cout<<a[0]*b[0]+a[1]*b[1]<<endl;
	}
	return 0;
}