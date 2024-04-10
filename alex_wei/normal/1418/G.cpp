#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define pb push_back

const int N=5e5+5;
const int mod=1e9+7;
const int base=131;
const int base2=37;

map <ll,int> mp;
map <ull,int> mp2;

ull hs2,pw2[N],pre2[N];
ll hs,ans,pre[N],pw[N];
int n,a[N],l,num[N],buc[N];

void add(int v){
	if(num[v]<2)hs=(hs+pw[v])%mod,hs2+=pw2[v];
	else hs=(hs-2*pw[v]%mod+mod)%mod,hs2-=2*pw2[v];
	num[v]=(num[v]+1)%3,buc[v]++;
	while(buc[v]>3)mp[pre[l]]--,mp2[pre2[l]]--,buc[a[++l]]--;
}

int main(){
	cin>>n,mp[0]=mp2[0]=1,pw[0]=pw2[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*base%mod,pw2[i]=pw2[i-1]*base2; 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(a[i]),ans+=min(mp2[hs2],mp[hs]),mp[pre[i]=hs]++,mp2[pre2[i]=hs2]++;	
	} cout<<ans<<endl;
	return 0;
}