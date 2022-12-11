#include<bits/stdc++.h>
#define int long long
using namespace std;
int query(int x){
	cout<<"? "<<x<<endl;
	cout.flush();
	int nans;
	cin>>nans;
	return nans;
}
void init();
int guess(int);
long long T,m,n,pri[100001],pp,na,pa;
pair<long long,long long>a[1001];
bool isprime(int x){for(int i=2;i<=sqrt(x);i++)if(x%i==0)return 0;return 1;}
long long qma(long long x){
	long long nt=1;
	while(nt<=1000000000000000000ll/x)nt*=x;
	return nt;
}
void init(){
	na=1;
	for(int i=2;i<=1000;i++){
		if(isprime(i)){
			pri[++pp]=i;
			na*=i;
		}
		if(na>1000000000000000000ll/i){
			a[++pa]=make_pair(pp,na);
			na=1;
		}
	}
//	for(int i=1;i<=pa;i++)cout<<a[i].first<<" "<<pri[a[i].first]<<" "<<a[i].second<<endl;
}
int guess(int M){
	int nans=1,maa=1000000000,ffl=0,hs=0;
	for(int i=1;i<=pa;i++){
		int nt=query(a[i].second);hs++;
		if(hs>=22)break;
		if(nt!=1){
			for(int j=a[i-1].first+1;j<=a[i].first;j++){
				if(nt%pri[j]==0){
					ffl++;
					long long ng=0,nr=qma(pri[j]),nq=query(nr);hs++;
					
					while(nq%pri[j]==0)ng++,nq/=pri[j];
					nans*=(ng+1);
					if(hs>=22){
						break;
					}
				}
			}
			maa/=nt;
		}
		if(hs>=22)break;
		if((long long)pri[a[i].first]*pri[a[i].first]*pri[a[i].first]>maa)break;
		if(pri[a[i].first]>=200&&!ffl)break;
	}
	if(!ffl)return 8;
	else return nans*2;
}
signed main(){
	cin>>T;
	init();
	while(T--){
		cout<<"! "<<guess(22)<<endl;
	}
}