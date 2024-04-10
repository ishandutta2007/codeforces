#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int BBB=320;
int n,a[100100],res,buc[40001000],b[200100];
map<pair<int,ll>,int>mp;
void mina(){
	for(int i=0;i<=BBB;i++){
		for(int j=1;j<=n;j++)res=max(res,++buc[a[j]+j*i]);
		for(int j=1;j<=n;j++)buc[a[j]+j*i]--;
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n&&j<=i+BBB;j++){
		if(a[j]<a[i])continue;
		int dif=a[j]-a[i];
		if(dif%(j-i))continue;
		dif/=j-i;
		if(dif<BBB)continue;
		res=max(res,b[++mp[make_pair(dif,a[i]-1ll*i*dif)]]);
	}
	mp.clear();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=BBB;i++)b[i*(i-1)>>1]=i;
	mina();
	reverse(a+1,a+n+1);
	mina();
	printf("%d\n",n-res);
	return 0;
}