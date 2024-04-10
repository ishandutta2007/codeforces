#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(A) A.begin(),A.end()
const int inf=1018181818;
using namespace std;
int n;
int a[200005];
map <int,int> m;
int o[200005];
int k;

int check(int x) {
//	cout<<lower_bound(o+k,o+k,5)-o<<endl;
//	bool debug=(x==3);
//	cout<<(*(--o.end()))<<endl;
	int res=0;
	int now=-1;
	while(true) {
//		if(debug)
//		{
//			cout<<o[0]<<' ';
//			cout<<o[1]<<' ';
//			cout<<o[2]<<' ';
//			cout<</*o[3]<<*/endl;
//		}
		now=lower_bound(o+now+1,o+k,x)-o;
//		if(debug) cout<<x<<'-'<<now<<endl;
		if(now>=k) break;
		res+=x;
		x<<=1;
	}
	return res;
}

int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		scanf("%d",a+i);
		m[a[i]]++;
	}
	for(map <int,int> :: iterator it=m.begin(); it!=m.end(); it++) {
		o[k++]=it->second;
	}
	sort(o,o+k);
	int maxn=-1;
	for(int i=n; i>=1; i--) {
//		cout<<i<<' '<<check(i)<<endl;
		maxn=max(maxn,check(i));
	}
	cout<<maxn<<endl;
	return 0;
}