#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int a[N];
bool b[8199];
vector<tuple<int,int,int>>ans,a2[8199];
void eb(int i,int j,int k){
	ans.emplace_back(i,j,k),a[i]^=1,a[j]^=1,a[k]^=1;
}
queue<int>q;
int main(){
	int n,ii,i,j,k,l,t;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;;i+=3){
		if(n-i+1<=13)break;
		if(a[i]&&a[i+1]&&a[i+2])eb(i,i+1,i+2);
		else if(a[i+1]&&a[i+2])eb(i+1,i+2,i+3);
		else if(a[i]&&a[i+2])eb(i,i+2,i+4);
		else if(a[i]&&a[i+1]){
			i+=3;
			if(a[i]&&a[i+1]&&a[i+2])eb(i-2,i,i+2),eb(i-3,i+1,i+5);
			else if(a[i]&&a[i+1])eb(i-3,i,i+3),eb(i-2,i+1,i+4);
			else if(a[i]&&a[i+2])eb(i-3,i,i+3),eb(i-2,i+2,i+6);
			else if(a[i+1]&&a[i+2])eb(i-3,i+1,i+5),eb(i-2,i+2,i+6);
			else if(a[i])eb(i-3,i,i+3),eb(i-2,i+3,i+8);
			else if(a[i+1])eb(i-3,i+1,i+5),eb(i-2,i+3,i+8);
			else if(a[i+2])eb(i-3,i+2,i+7),eb(i-2,i+3,i+8);
			else eb(i-3,i-2,i-1),eb(i-1,i+3,i+7);
		}else if(a[i])eb(i,i+3,i+6);
		else if(a[i+1])eb(i+1,i+3,i+5);
		else if(a[i+2])eb(i+2,i+3,i+4);
	}
	for(n-=i-1,j=k=0;j<n;++j)if(a[i+j])k|=1<<j;
	q.push(k),b[k]=1,ii=i;
	if(k)while(q.size()){
		i=q.front(),q.pop();
		for(j=0;j<n;++j)for(k=j-1,l=j+1;k>=0&&l<n;--k,++l){
			t=i^((1<<j)|(1<<k)|(1<<l));
			if(!b[t]){
				b[t]=1,q.push(t),a2[t]=a2[i],a2[t].emplace_back(k,j,l);
				if(!t)goto gg;
			}
		}
	}
	gg:;
	if(!b[0])puts("NO");
	else{
		puts("YES");
		cout<<ans.size()+a2[0].size()<<'\n';
		for(auto o:ans)cout<<get<0>(o)<<' '<<get<1>(o)<<' '<<get<2>(o)<<'\n';
		for(auto o:a2[0])cout<<get<0>(o)+ii<<' '<<get<1>(o)+ii<<' '<<get<2>(o)+ii<<'\n';
	}
	return 0;
}