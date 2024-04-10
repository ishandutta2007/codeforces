#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	while(n--){
		int ans=0,a,b,c;
		cin>>a>>b>>c;
		int t1=min(c/2,b);
		b-=t1;
		int t2=min(b/2,a);
		cout<<3*(t1+t2)<<endl;
	}
	return 0;
}