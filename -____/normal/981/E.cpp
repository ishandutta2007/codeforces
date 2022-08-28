//CF 981E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 10005;
const int T = 33333;
int n,q;
bitset<N> b[T],ans;
vector<int> v[T];
void modify(int L,int R,int x,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		v[k].push_back(x);
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,x,k<<1,l,h);
	if(h<R)
		modify(L,R,x,k<<1|1,h+1,r);
}
void go(int k=1,int l=1,int r=n){
	b[k]=b[k>>1];
	for(int i=v[k].size();i--;)
		b[k]|=(b[k]<<v[k][i]);
	if(l==r){
		ans|=b[k];
		return;
	}
	int h=l+r>>1;
	go(k<<1,l,h);
	go(k<<1|1,h+1,r);
}
int main()
{
	int i,l,r,x;
	scanf("%d%d",&n,&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d%d%d",&l,&r,&x);
		modify(l,r,x);
	}
	b[0].set(0);
	go(1);
	x=0;
	for(i=1;i<=n;i=i+1)
		if(ans[i])
			x++;
	cout<<x<<endl;
	for(i=1;i<=n;i=i+1)
		if(ans[i])
			cout<<i<<' ';
	return 0;
}