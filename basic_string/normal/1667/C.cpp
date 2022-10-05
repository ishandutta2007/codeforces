#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,k,w,ji,ou;
	cin>>n;
	if(n==1){cout<<1<<'\n';cout<<1<<' '<<1<<'\n';return 0;}
	k=(2*n+1)/3;
	cout<<k<<'\n';
	w=n-k-1;
	ji=w,ou=w;
	if(ji%2==0)--ji;else --ou;
	int x=ji+1,y,i;
	for(i=1;i<=x;++i)cout<<i<<' '<<x-i+1<<'\n';
	y=ou+1;
	for(i=1;i<=y;++i)cout<<x+i<<' '<<x+y-i+1<<'\n';
	x+=y;
	for(i=x+1;i<=k;++i)cout<<i<<' '<<i<<'\n';
}/*
3+1

2+0*/
/*
nkk
w=n-k-1
-w,-w+1...w-1,wp[i]-i
1 2 3 4 5 6 7 8 9

11
23
32
w*2+1<=k
3k>=2n-1
k>=(2n-1)/3
n=5 k=3
n=6 k=4
n=7 k=5
n=8 k=5?
13
31
45
54
22
n=11 k=7?
14
41
23
32
57
75
66 
*/