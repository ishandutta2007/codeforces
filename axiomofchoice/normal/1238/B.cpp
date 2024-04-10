#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
int q,a[100010],n,r;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>q;
	while(q--){
		cin>>n>>r;
		repeat(i,0,n)cin>>a[i];
		sort(a,a+n);
		int x=n-1,ans=0,RR=0;
		while(1){
			if(x<0 || a[x]-RR<=0)break;
			ans++;
			RR+=r;
			int t=a[x];
			while(x>=0 && a[x]==t)x--;
		}
		cout<<ans<<endl;
	}
	return 0;
}