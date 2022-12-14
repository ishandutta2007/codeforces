#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<4)cout<<4-n<<endl;
		else cout<<int(n%2==1)<<endl;
	}
	return 0;
}