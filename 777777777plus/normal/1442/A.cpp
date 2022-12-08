#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n;
int a[N],l[N];
bool canl[N],canr[N];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		l[0]=1e9;
		l[1]=a[1];
		bool flag=1;
		for(int i=2;i<=n;++i){
			l[i]=min(l[i-1],a[i]-a[i-1]+l[i-1]);
			if(l[i]<0)flag=0;
		}
		if(flag)puts("YES");
		else puts("NO");
	}
}