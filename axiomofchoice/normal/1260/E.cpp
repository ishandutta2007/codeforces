#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 262194
//#define mod 1000000007
#define int ll
#define inf 1e9
#define qwq {cout<<"qwq"<<endl;}
int n,fr;
int a[N];
priority_queue<int> q;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	int m=n,s=0;
	while(m)m>>=1,s++;s--;
	//cout<<s<<endl;
	repeat(i,0,n){
		cin>>a[i];
		if(a[i]==-1)fr=i;
	}
	int p=1,cnt=0;
	while(p-1<=fr)p<<=1,cnt++;cnt--;
	//cout<<cnt<<endl;
	cnt=s-cnt;
	
	int top=n-1,ans=0; m=n/2;
	if(top!=fr)q.push(-a[top--]);
	while(cnt>0){//cout<<1<<endl;
		ans-=q.top();
		q.pop(); cnt--;
		repeat(i,0,m)
			if(top!=fr)q.push(-a[top--]);m/=2;
	}
	cout<<ans<<endl;
	return 0;
}