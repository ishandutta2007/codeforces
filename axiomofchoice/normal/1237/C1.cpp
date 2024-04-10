#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
int n,f[50010];
struct node{
	int x,y,z;
}a[50010];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	repeat(i,0,n){
		cin>>a[i].x>>a[i].y>>a[i].z;f[i]=1;
	}
	repeat(i,0,n)if(f[i]){
		int p=0;
		repeat(j,i+1,n)if(f[j])
		if(p==0)
			p=j;
		else
		if(min(a[i].x,a[p].x)<=a[j].x
		&& a[j].x<=max(a[i].x,a[p].x) &&
		min(a[i].y,a[p].y)<=a[j].y
		&& a[j].y<=max(a[i].y,a[p].y) &&
		min(a[i].z,a[p].z)<=a[j].z
		&& a[j].z<=max(a[i].z,a[p].z))
			p=j;
		cout<<i+1<<' '<<p+1<<endl;
		f[i]=f[p]=0;
	}
	return 0;
}