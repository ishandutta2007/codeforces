#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=500010; typedef long long ll;
#define int ll
int n,cnt;
vector<int> a,b;
deque<char> ans;
void rev(){ //b
	reverse(b.begin(),b.end());
	ans.push_front('R');
}
int ok(){ //ab
	if(a==b)return 1;
	repeat(i,0,n)
		if(a[i]!=b[n-i-1])return 0;
	ans.push_front('R'); //
	return 1;
}
int down(){ //(n>=3)
	if(ok())return 1;
	if(b[0]>b[1])rev();
	repeat(i,0,n-1)if(b[i]>=b[i+1])return -1;
	repeat_back(i,1,n)b[i]-=b[i-1];
	ans.push_front('P'); cnt++;
	return 0;
}
void push(int x){ //x
	cnt+=x;
	b[1]-=b[0]*x;
	while(x--){
		if(ans.size()>N)return;
		ans.push_front('P');
	}
}
int down2(){ //(n>=2)
	if(ok())return 1;
	if(b[0]>b[1])rev();
	if(a[0]>b[0] || a[1]>b[1])return -1;
	int t=max((b[1]-a[1])/b[0],1ll);
	push(t);
	return 0;
}
void output(int ok){ //
	if(ok){
		if(cnt<=200000){
			cout<<"SMALL"<<endl<<ans.size()<<endl;
			for(auto i:ans)cout<<i; cout<<endl;
		}
		else cout<<"BIG"<<endl<<cnt<<endl;
	}
	else cout<<"IMPOSSIBLE"<<endl;
}
signed main(){
	cin>>n; a=b=vector<int>(n);
	repeat(i,0,n)cin>>a[i];
	repeat(i,0,n)cin>>b[i];
	if(n==1)output(a[0]==b[0]);
	else if(n==2){
		int flag=0;
		if(a[0]>a[1]){ //
			swap(a[0],a[1]);
			flag=1;
		}
		int t;
		do t=down2(); while(t==0);
		if(flag)ans.push_front('R');
		output(t==1);
	}
	else{
		int t;
		do t=down(); while(t==0);
		output(t==1);
	}
	return 0;
}