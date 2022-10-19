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
int n,a[N];
void print(){
	printf("! ");
	rep(i,1,n) printf("%d ",a[i]);
	fflush(stdout);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	int a12 = AND(1,2),o12 = OR(1,2),x12 = o12-a12,a13 = AND(1,3),o13 = OR(1,3),x13 = o13-a13;
 	int x23 = x13^x12,a23 = AND(2,3),o23 = x23 + a23;
 	int XY = (a12+o12),YZ = (a23+o23),XZ = (a13+o13);
 	//printf("%d %d %d\n%d %d %d\n%d %d %d\n",a12,o12,x12,a23,o23,x23,a13,o13,x13);
 	a[1] = (XY+YZ+XZ)/2-YZ;
 	a[2] = (XY+YZ+XZ)/2-XZ;
 	a[3] = (XY+YZ+XZ)/2-XY;
 	rep(i,4,n){
 		int t = XOR(1,i);
 		a[i] = t^a[1];
 	}
 	print();
	return 0;
}