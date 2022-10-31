#include<bits/stdc++.h>
using namespace std;
int a[400100],b[400100];
int sz[400100];
vector<pair<int,int> > p; 
int main(){
	int n,m=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int mx=0,cnt=0;
	for(int i=0;i<n;i++){
		if(i&&a[i]==a[i-1]) cnt++,p.back().first--;
		else cnt=1,p.push_back(make_pair(-1,a[i]));
		sz[cnt]++;
		mx=max(mx,cnt);
	}
	int ms=0,mi,tmp=n;
	for(int i=n;i>=1;i--){
		if(tmp/i>=i&&tmp/i*i>=ms) ms=tmp/i*i,mi=i; 
		tmp-=sz[i];
	}
	sort(p.begin(),p.end());
	for(int i=0;i<p.size();i++){
		if(p[i].first<-mi) p[i].first=-mi;
		for(int j=0;j<-p[i].first;j++){
			b[m++]=p[i].second;
		}
	}
	assert(m>=ms);
	printf("%d\n",ms);
	printf("%d %d\n",ms/mi,mi);
	for(int i=0;i<ms/mi;i++){
		for(int j=0;j<mi;j++){
			if(j) putchar(' ');
			printf("%d",b[(i-j+ms/mi)%(ms/mi)*mi+j]);
		}
		puts("");
	}
	return 0;
}