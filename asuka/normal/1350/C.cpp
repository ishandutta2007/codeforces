#include<bits/stdc++.h>
#define int long long
#define N 200015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,a[N],pre[N],pri[N],cnt,sum[N];
priority_queue<int,vector<int>,greater<int> > q[N];
void get(int x){
	for(int i = 2;i <= x;++i){
		bool flag = 0;
		for(int j = 2;j*j <= i;++j){
			if(i%j == 0){
				pre[i] = j;
				flag = 1;
				break;
			}
		}
		if(flag == 0) pri[++cnt] = i,pre[i] = i;
	}
	return;
}
void frac(int x){
	//cout << x << ": \n";
	while(x > 1){
		int t = pre[x],c = 1;
		x /= pre[x];
		//cout << x << endl;
		while(pre[x] == t){
			c++;
			x /= pre[x];
			//cout << x << endl;
		}
		//cout << t <<  ' ' << c << endl;
		q[t].push(c);
	}
}
int qpow(int x,int y){
	int res = 1;
	while(y){
		if(y&1) res = res*x;
		x = x*x;
		y>>=1;
	}
	return res;
} 
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	get(200000);
	cin>>n;
	rep(i,1,n) cin>>a[i];
	int ans = 1;
	rep(i,1,n) frac(a[i]);
//	rep(i,1,100) cout << pri[i] << endl;
	rep(i,1,cnt){
		if(q[pri[i]].size() < n-1) continue;
		if(q[pri[i]].size() == n) q[pri[i]].pop();
		//cout <<pri[i] << ' ' << q[pri[i]].top() << endl;
		ans *= qpow(pri[i],q[pri[i]].top());
	}
	cout << ans << endl;
	return 0;
}