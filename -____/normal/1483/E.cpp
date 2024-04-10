#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL M = 1e14;
LL m;
LL s,mn,mx;
int cnt;
int query(LL x){
	x=min(x,M);
	while(s<x&&mn<x){
		query(mn);
	}
	cnt++;
	string p;
	cout<<"? "<<x<<endl;
	cin>>p;
	/*if(x<=m)
		p="L";
	else
		p="F";*/
	if(p[0]=='L'){
		s+=x;
		return 1;
	}
	s-=x;
	return 0;
}
void solve(){
	int i;
	LL l,r;
	s=1,mn=1,mx=M;
	for(i=1;i<=46;i++){
		if(!query(s))
			break;
		mn=s/2;
	}
	if(i==1){
		cout<<"! 0"<<endl;
		return;
	}
	if(i<=46)
		mx=min(mx,mn*2-1);
	while(mn<mx){
		l=(mn*2+mx+2)/3;
		r=(mn+mx*2+2)/3;
		if(query(l)){
			mn=l;
			if(mn==mx)
				break;
			if(query(r)){
				mn=r;
			}
			else{
				mx=r-1;
			}
		}
		else{
			mx=l-1;
		}
	}
	if(cnt>105)
		cout<<1/0;
	cout<<"! "<<mn<<endl;
	//if(mn!=m)
	//	exit(233);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		//cin>>m;
		//m=((LL)rand()<<35)^((LL)rand()<<20)^rand();m%=M;m++;
		//m=(LL)rand()<<45|(LL)rand()<<30|rand()<<15|rand();
		//m%=M,m++;
		//m=(LL)1<<45;
		cnt=0;
		solve();
		//if(cnt>105)cout<<cnt<<' '<<m<<endl;
	}
	return 0;
}