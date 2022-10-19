#include<bits/stdc++.h>
#define int long long
#define N 1000015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define left fuck
#define right ffuucckk
#define All(x) x.begin(),x.end()
#define debug(x) for(auto v:x) cout << v.l << ' ' << v.r << endl;cout <<"end" << endl;
using namespace std;
int n,m,t[N],ans;
const int M = 1e6;
struct hori{
	int l,r,y;
	hori(){}
	hori(int a,int b,int c){l = a;r = b;y = c;}
	bool operator<(const hori&o) const{
		if(l == 0) return o.r < r;
		if(r == M) return o.l > l;
	}
};
struct ver{
	int l,r,x;
	ver(){}
	ver(int a,int b,int c){l = a;r = b;x = c;}
	bool operator<(const ver&o) const{
		return x < o.x;
	}
};
struct BIT{
	int a[N];
	void add(int x,int d){
		x++;
		for(;x<=M+1;x+=lowbit(x)) a[x]+=d;
	}
	int query(int x){
		x++;
		int res = 0;
		for(;x;x-=lowbit(x)) {res+=a[x];}
		return res;
	}
	int query(int l,int r){
		return query(r)-query(l-1);
	}
}A,B;
vector<ver> line;
vector<hori> left,right;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>n>>m;
 	rep(i,1,n){
 		int l,r,y;
 		cin>>y>>l>>r;
 		if(l == 0) left.pb(hori(l,r,y));
 		else if(r == M) right.pb(hori(l,r,y));
 		if(l==0&&r==M) ans++;
 	}
 	//left.pb(hori(0,M,0));//left.pb(hori(0,M,M));
 	//right.pb(hori(0,M,0));right.pb(hori(0,M,M));
 	rep(i,1,m){
 		int l,r,y;
 		cin>>y>>l>>r;
 		if(l == 0&&r == M) ans++;
 		line.pb(ver(l,r,y));
 	}
 	//line.pb(ver(0,M,M));
 	sort(All(line));sort(All(left));sort(All(right));
 	//debug(line)debug(left)debug(right)
 	int sz = line.size(),z = right.size();
 	//cout << "z: " << z << " sz: " << sz << endl;
 	int cur = 0;
 	rep(i,0,sz-1){
 		//cout << i << ' ' << line[i].x << ' ' << line[i].l << ' ' << line[i].r << endl; 
 		while(cur < z&&right[cur].l <= line[i].x){
 			//cout << "cur: " << cur  << " l: " << right[cur].l << " r: " << right[cur].r << " y: " << right[cur].y << endl;
 			A.add(right[cur].y,1);
 			cur++;
 		}
 		//cout << "ans: " << max(A.query(line[i].l,line[i].r)-1,0ll) << endl;
 		//ans += max(A.query(line[i].l,line[i].r)-1,0ll);
 		t[i] += A.query(line[i].l,line[i].r);
 		//cout << A.query(0) << ' ' << A.query(M) << endl;
 	}
 	cur = 0,z = left.size();
 	per(i,0,sz-1){
 		//cout << i << ' ' << line[i].x << ' ' << line[i].l << ' ' << line[i].r << endl; 
		while(cur < z&&left[cur].r >= line[i].x){
		//	cout << "cur: " << cur << endl;
	 		B.add(left[cur].y,1);
	 		cur++;
	 	}
	 	//ans += max(B.query(line[i].l,line[i].r)-1,0ll);
	 	t[i] += B.query(line[i].l,line[i].r);
	 	//cout << "ans: " << max(B.query(line[i].l,line[i].r)-1,0ll) << endl;
 	}
 	rep(i,0,sz-1) ans += max(t[i],0ll);
 	printf("%lld\n",ans+1);
	return 0;
}