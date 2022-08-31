#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 44;
vector<int> v[3];
void ans(int x,int y,int z){
	v[0].push_back(x);
	v[1].push_back(y);
	v[2].push_back(z);
}
int n=32,L,R,l[N],r[N];
int main()
{
	int i,t;
	l[1]=0,r[1]=0;
	for(i=1;i<=30;i=i+3){
		t=r[i]-l[i]+1;
		ans(i,i+1,1);
		l[i+1]=l[i]+1,r[i+1]=r[i]+1;
		ans(i,i+2,1);
		ans(i+1,i+2,t);
		l[i+2]=l[i]+1,r[i+2]=r[i]+1+t;
		ans(i,i+3,1);
		ans(i+1,i+3,t);
		ans(i+2,i+3,t*2);
		l[i+3]=l[i]+1,r[i+3]=r[i]+1+t*3;
	}
	cin>>L>>R;
	for(i=31;i>=1;i=i-1){
		if(r[i]<R&&r[i]-l[i]<=R-L){
			ans(i,n,R-r[i]);
			R=l[i]-1+R-r[i];
		}
	}
	printf("YES\n%d %d\n",n,v[0].size());
	for(i=0;i<v[0].size();i=i+1)
		printf("%d %d %d\n",v[0][i],v[1][i],v[2][i]);
	return 0;
}