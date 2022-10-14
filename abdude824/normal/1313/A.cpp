#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int C[][3]={
	{0,0,1},
	{0,1,0},
	{1,0,0},
	{0,1,1},
	{1,0,1},
	{1,1,0},
	{1,1,1}
};
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int T=gi();
	while(T--){
		int a=gi(),b=gi(),c=gi(),ans=0;
		for(int i=0;i<1<<7;++i){
			int sa=0,sb=0,sc=0;
			for(int j=0;j<7;++j)if(i>>j&1)sa+=C[j][0],sb+=C[j][1],sc+=C[j][2];
			if(sa<=a&&sb<=b&&sc<=c)ans=std::max(ans,__builtin_popcount(i));
		}
		printf("%d\n",ans);
	}
	return 0;
}