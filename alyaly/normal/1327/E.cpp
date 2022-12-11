#include<bits/stdc++.h>
#define int long long
#define P 998244353
using namespace std;
string s;
int n,ans[200001],tenp[200001];
int f(int k){
	if(k==n-1) return 90ll;
	else{
		int nt=90ll*tenp[n-k-1];
		return nt%P;
	}
}
void cal(int k){
	ans[k]+=2*f(k)%P;
	if(k<n-1){
		ans[k]+=(n-k-1)*810ll*tenp[n-k-2];
		ans[k]%=P;
	}
	return;
}
string tostr(int x){
	string ns;
	for(int i=tenp[n-1];i>=1;i/=10){
		ns+=(x/i)+'0';
		x%=i;
	}
	return ns;
}
signed main(){
	cin>>n;
	tenp[0]=1;
	for(int i=1;i<=n;i++){
		tenp[i]=tenp[i-1]*10ll;
		tenp[i]%=P;
	}
//	for(int i=0;i<tenp[n];i++){
//		s+=tostr(i);
//	}
//	int nn=0;
//	cout<<s<<endl;
//	for(int i=1;i<s.size()-1;i++){
//		if(s[i]!=s[i-1]&&s[i]!=s[i+1]){
//			nn++;
//		}
//	}
//	printf("%d\n",nn);
//	return 0;
	for(int i=1;i<n;i++){
		cal(i);
	}
	for(int i=1;i<n;i++) printf("%lld\n",ans[i]);
	printf("10\n");
	return 0;
}