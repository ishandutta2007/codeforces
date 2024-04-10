#include<bits/stdc++.h>
#define ll long long
#define N ((1<<16)+15)
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
using namespace std;
int OR(int i,int j){
	int x;
	printf("OR %d %d\n",i,j);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int AND(int i,int j){
	int x;
	printf("AND %d %d\n",i,j);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int XOR(int i,int j){
	int x;
	printf("XOR %d %d\n",i,j);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int sum(int i,int j){
	return AND(i,j)+OR(i,j);
}
int n,a[N],p[N];
map<int,int> M;
void calc(){
	rep(i,2,n) a[i] = a[1]^p[i];
}
void print(){
	printf("! ");
	rep(i,1,n) printf("%d ",a[i]);
	fflush(stdout);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	rep(i,2,n) p[i] = XOR(1,i);
 	bool f1,f2; f1 = f2 = 0;
 	int p1,p2;
 	rep(i,2,n) {
 		if(p[i] == 0) {f1 = 1; p1 = i; break;}
 		if(M.count(p[i])) {f2 = 1,p1 = M[p[i]]; p2 = i; break;}
 		M[p[i]] = i;
 	}
 	if(f1){
 		a[1] = AND(1,p1);
 		calc();
 		print();
 		return 0;
 	}
 	if(f2){
 		a[p1] = AND(p1,p2);
 		a[1] = a[p1]^p[p1];
 		calc();
 		print();
 		return 0;
 	}
 	rep(i,2,n){
 		if(p[i] == 1) p1 = i;
 		if(p[i] == 2) p2 = i;
 	}
 	a[1] = AND(1,p1); int tmp = AND(1,p2);
 	if(tmp&1) a[1] ^= 1;
 	calc();
 	print();
	return 0;
}