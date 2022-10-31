#include<bits/stdc++.h>
#define Q 1000000007
using namespace std;
long long hv(const string &s, int p, int x){
	long long a=514,b=60229,ra=0,rb=0;
	while(x<s.size()){
		ra=(ra*a+s[x])%Q;
		rb=(rb*b+s[x])%Q;
		x+=p;
	}
	return ra*Q+rb;
}
long long ph[2010],sh[210];
char tmp[2010];
int good[2010][210];
int solve(int st,int ed,int ss,int es){
	if(st==ed)	{
		if(ss==es) return 1;
		else return -1;
	}
	if(good[st][ss]) return good[st][ss];
	if(solve(st+1,ed,ss,es)>0){
		return good[st][ss]=1;
	}
	else if(ss<es && ph[st]==sh[ss]&&solve(st+1,ed,ss+1,es)>0){
		return good[st][ss]=2;
	}
	else return good[st][ss]=-1;
}
void track(int st,int ed,int ss){
	while(st<ed){
		assert(good[st][ss]>0);
		tmp[st]='0'-1+good[st][ss];
		ss+=good[st][ss]-1;
		st++;
	}
}
int main(){
	string p,s;
	getline(cin,p);
	getline(cin,s);
	int k;
	string ans("0");
	bool flag=false;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		ph[i]=hv(p,k,i);
	}
	int q=p.size()/k,r=p.size()%k;
	int nt,nr;
	//s.len=nt*q+nr
	if(q==0){
		nt=s.size();
		nr=s.size();
	}
	else{
		nt=s.size()/q;
		nr=s.size()%q;
	}
	while(nr<=nt){
		for(int i=0;i<nt;i++){
			sh[i]=hv(s,nt,i);
		}
		memset(good,0,sizeof(good));
		if(solve(0,r,0,nr)>0 && (q==0||solve(r,k,nr,nt)>0)){
			track(0,r,0);
			if(q) track(r,k,nr);
			if(!flag||string(tmp)<ans){
				ans=string(tmp);
				flag=true;
			}
		}
		nt--;
		nr+=q;
	}
	while(flag&&ans.size()<k) ans.push_back('0');
	cout<<ans<<endl;
	return 0;
}