#include<bits/stdc++.h>
#define N 400100
using namespace std;
vector<int> l[N],r[N];
int a[N],llen,rlen;
int u[N];
bool cmp(int i,int j){
	return a[i]>a[j];
}
int main(){
	int n,m,x,y,el,er;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		int sl=0,sr=llen+1;
		while(sl+1<sr){
			int sm=(sl+sr)/2;
			if(a[i]>a[l[sm-1].back()]) sl=sm;
			else sr=sm;
		}
		if(sl==llen){
			llen++;
		}
		l[sl].push_back(i);
	}
	for(int i=llen-1;i>=0;i--){
		if(i==llen-1){
			el=l[i][0];
			er=l[i].back();
		}
		else{
			el=*upper_bound(l[i].begin(),l[i].end(),el,cmp);
			er=*(lower_bound(l[i].begin(),l[i].end(),er)-1);
		}
		if(el==er) u[el]=1;
	}
	for(int i=n-1;i>=0;i--){
		int sl=0,sr=rlen+1;
		while(sl+1<sr){
			int sm=(sl+sr)/2;
			if(!sm||a[i]<a[r[sm-1].back()]) sl=sm;
			else sr=sm;
		}
		if(sl==rlen){
			rlen++;
		}
		r[sl].push_back(i);
	}
	while(m--){
		scanf("%d%d",&x,&y);
		x--;
		int ll=0,lr=llen+1,rl=0,rr=rlen+1;
		while(ll+1<lr){
			int sm=(ll+lr)/2;
			auto it=lower_bound(l[sm-1].begin(),l[sm-1].end(),x);
			if(it!=l[sm-1].begin()&&y>a[*(it-1)]) ll=sm;
			else lr=sm;
		}
		while(rl+1<rr){
			int sm=(rl+rr)/2;
			auto it=lower_bound(r[sm-1].begin(),r[sm-1].end(),x,greater<int>());
			if(it!=r[sm-1].begin()&&y<a[*(it-1)]) rl=sm;
			else rr=sm;
		}
		printf("%d\n",max(llen-u[x],ll+rl+1));
	}
}