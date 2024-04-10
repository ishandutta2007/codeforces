#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,k;
int a[N];
int b[N],mn[N];

bool can(int res){
	for(int i=1;i<=n;++i)b[i]=a[i]>=res?1:-1;
	for(int i=1;i<=n;++i)b[i]+=b[i-1];
	mn[0]=0;
	for(int i=1;i<=n;++i)mn[i]=min(mn[i-1],b[i]);
	for(int i=k;i<=n;++i){
		if(b[i]>mn[i-k]){
			return 1;
		}
	}
	return 0;
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int l=1,r=n;
	while(l!=r){
		int mid=l+r+1>>1;
		if(can(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
}