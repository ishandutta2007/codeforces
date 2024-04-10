#include<bits/stdc++.h>
using namespace std;
int T,n,L,R,a[200100],res;
vector<int>v;
int main(){
//	freopen("I.in","r",stdin);
//	freopen("A.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&L,&R),res=0;
		for(int i=1,x;i<=L;i++)scanf("%d",&x),a[x]++;
		for(int i=1,x;i<=R;i++)scanf("%d",&x),a[x]--;
		for(int i=1;i<=n;i++){
			if(a[i]&1){
				if(a[i]>0&&!v.empty()&&a[v.back()]<0)res++,a[i]--,a[v.back()]++,v.pop_back();
				if(a[i]<0&&!v.empty()&&a[v.back()]>0)res++,a[i]++,a[v.back()]--,v.pop_back();
				if(a[i]&1)v.push_back(i);				
			}
		}
		for(int i=1;i<=n;i++){
			while(a[i]>0&&!v.empty()&&a[v.back()]<0)res++,a[i]--,a[v.back()]++,v.pop_back();
			while(a[i]<0&&!v.empty()&&a[v.back()]>0)res++,a[i]++,a[v.back()]--,v.pop_back();
		}
		res+=v.size();
		while(!v.empty()){
			if(a[v.back()]>0)a[v.back()]--,L--;
			if(a[v.back()]<0)a[v.back()]++,R--;
			v.pop_back();
		}
		for(int i=1;i<=n;i++)res+=abs(a[i])/2,a[i]=0;
		printf("%d\n",res);
	}
	return 0;
}
/*
1
6 3 3
2 5 2 6 4 2
*/