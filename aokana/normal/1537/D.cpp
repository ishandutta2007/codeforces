#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
vector<int>pri;
bool vis[maxn];
inline bool check(int k){
	ri ret=0;
	vector<bool>flag(2);
	for(auto i:pri)
		if(k%i==0){
			flag[(i-1)&1]=true;
			while(k%i==0)ret+=i-1,k/=i;
		}
	if(k>1){
		flag[(k-1)&1]=true;
		ret+=k-1;
	}
	return flag[!(ret&1)];
}
int main(){
	for(ri i=2;i<=33333;++i){
		if(!vis[i])pri.push_back(i);
		for(ri j=0;j<pri.size()&&i*pri[j]<=33333;++j){
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		puts(check(n)?"Alice":"Bob");
	}
	return 0;
}