#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(A) A.begin(),A.end()
const int inf=1018181818;
using namespace std;

int main() {
	int t;
	cin>>t;
	int a,b,k;
	while(t--) {
		scanf("%d%d%d",&a,&b,&k);
		ll res=1LL*(a-b)*(k/2);
		k%=2;
		if(k) {
			res+=a;
			k--;
		}
		if(k) {
			res-=b;
			k--;
		}
		printf("%I64d\n",res);
	}
	return 0;
}