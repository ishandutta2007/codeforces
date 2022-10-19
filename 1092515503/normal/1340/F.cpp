#include<bits/stdc++.h>
using namespace std;
const int BBB=400;
int n,m,BLK[100100],lp[500],lim,a[100100];
typedef unsigned long long ull;
ull srd1=388211,srd2=517619,pov1[100100],pov2[100100];
struct HASH{
    ull val1,val2;
    int len;
    HASH(){
        val1=val2=0ull;
        len=0;
    }
    HASH(int ip){
        val1=val2=ip;
        len=1;
    }
    friend HASH operator +(const HASH &x,const HASH &y){
        HASH z;
        z.val1=x.val1*pov1[y.len]+y.val1;
        z.val2=x.val2*pov2[y.len]+y.val2;
        z.len=x.len+y.len;
        return z;
    }
    friend HASH operator -(const HASH &x,const HASH &y){
        HASH z;
        z.val1=x.val1-y.val1*pov1[x.len-y.len];
        z.val2=x.val2-y.val2*pov2[x.len-y.len];
        z.len=x.len-y.len;
        return z;
    }
    friend bool operator ==(const HASH &x,const HASH &y){
        if(x.len!=y.len)return false;
        if(x.val1!=y.val1)return false;
        if(x.val2!=y.val2)return false;
        return true;
    }
    friend bool operator !=(const HASH &x,const HASH &y){
        if(x.len!=y.len)return true;
        if(x.val1!=y.val1)return true;
        if(x.val2!=y.val2)return true;
        return false;
    }
};
bool ok[500];
struct STACK{
	vector<int>u;
	vector<HASH>v;
	void clear(){
		v.clear();
		u.clear();
	}
	void push_back(int ip){
		u.push_back(ip);
	}
	void pop_back(){
		u.pop_back();
	}
	int size(){
		return u.size();
	}
	void recalc(){
		v.resize(u.size());v[0]=HASH();
		for(int i=1;i<v.size();i++)v[i]=v[i-1]+HASH(u[i]);
	}
	void rev(){
		reverse(u.begin(),u.end());
	}
}ls[500],rs[500];
vector<pair<int,int> >stk;
void func(int ip,int L=-1,int R=-1){
	if(L==-1&&R==-1)L=lp[ip],R=lp[ip+1];
	ls[ip].clear(),rs[ip].clear(),ok[ip]=true;
	ls[ip].push_back(0);
	for(int i=L;i<R;i++){
		if(a[i]>0)ls[ip].push_back(a[i]);
		else if(ls[ip].size()==1)rs[ip].push_back(-a[i]);
		else if(a[i]+*ls[ip].u.rbegin()==0)ls[ip].pop_back();
		else {ok[ip]=false;return;}
	}
	rs[ip].push_back(0),rs[ip].rev();
	ls[ip].recalc(),rs[ip].recalc();
//	printf("%d:\n",ip);for(auto x:ls[ip].u)printf("%d ",x);puts("");for(auto x:rs[ip].u)printf("%d ",x);puts("");
}
bool ins(int ip){
	if(!ok[ip])return false;
	int j=rs[ip].size()-1;
	while(j){
		if(stk.empty())return false;
		int mn=min(j,stk.rbegin()->second),pos=stk.rbegin()->first,len=stk.rbegin()->second;
		if((ls[pos].v[len]-ls[pos].v[len-mn])!=(rs[ip].v[j]-rs[ip].v[j-mn]))return false;
		j-=mn;
		if(!(stk.rbegin()->second-=mn))stk.pop_back();
	}
	if(ls[ip].size()!=1)stk.push_back(make_pair(ip,ls[ip].size()-1));
	return true;
}
bool mat(int L,int R){
	L--;
	stk.clear();
	if(BLK[L]==BLK[R]){
		func(lim+1,L,R);
//		for(int i=1;i<ls[lim+1].size();i++)printf("%d ",ls[lim+1].u[i]);puts("");
//		for(int i=1;i<rs[lim+1].size();i++)printf("%d ",rs[lim+1].u[i]);puts("");
//		printf("%d\n",ok[lim+1]);
		if(!ins(lim+1))return false;
		return stk.empty();
	}
	func(lim+1,L,lp[BLK[L]+1]);
	if(!ins(lim+1))return false;
	for(int i=BLK[L]+1;i<BLK[R];i++)if(!ins(i))return false;
	func(lim+2,lp[BLK[R]],R);
	if(!ins(lim+2))return false;
	return stk.empty();
}
int main(){
	scanf("%d%d",&n,&m);
	pov1[0]=pov2[0]=1;
	for(int i=1;i<=n;i++)pov1[i]=pov1[i-1]*srd1,pov2[i]=pov2[i-1]*srd2;
	for(int i=0;i<n;i++)scanf("%d",&a[i]),BLK[i]=i/BBB;
	BLK[n]=BLK[n-1]+1,lim=BLK[n],lp[lim]=n;
	for(int i=0;i<lim;i++)lp[i]=i*BBB;
	for(int i=0;i<lim;i++)func(i);
	scanf("%d",&m);
	for(int i=0,x,l,r;i<m;i++){
		scanf("%d%d%d",&x,&l,&r);
		if(x==1)l--,a[l]=r,func(BLK[l]);
		else puts(mat(l,r)?"Yes":"No");
	}
	return 0;
}
/*
10 1
1 -1 1 -1 1 -1 1 1 -1 -1 
11
2 1 2
2 1 3
2 1 5
2 2 4
2 3 5
2 4 8
2 5 8
2 7 10
2 4 10
2 1 5
2 4 5
*/