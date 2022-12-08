#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,x;
int a[N];
ll s[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>x;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
		int l=0,r=n;
		while(l!=r){
			int mid=l+r+1>>1;
			if(s[mid]>=1ll*x*mid)l=mid;
			else r=mid-1;
		}
		cout<<l<<endl;
	}
}