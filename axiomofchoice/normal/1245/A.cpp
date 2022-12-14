#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 100010
#define inf 1e9
int T,a,b;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>a>>b;
		if(__gcd(a,b)!=1)cout<<"In";
		cout<<"finite"<<endl;
	}
	return 0;
}