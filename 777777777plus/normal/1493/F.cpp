#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n,m;
bool flag;
int tim;
bool cr(int n,int m,int i1,int j1,int i2,int j2){
	if(flag){
		swap(n,m);
		swap(i1,j1);
		swap(i2,j2);
	}
	printf("? %d %d %d %d %d %d\n",n,m,i1,j1,i2,j2);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}

bool work(int n1,int k){
	int n=n1*k;
	while(n1*2<=n){
		if(!cr(n1,m,1,1,1+n1,1)){
			return 0;
		}
		n1*=2;
	}
	if(n1<n){
		if(!cr(n-n1,m,1,1,1+n1,1)){
			return 0;
		}
	}
	return 1;
}

ll work(){
	vector<int> a,b;
	int tmpn=n;
	for(int i=2;i<=tmpn;++i)
	if(tmpn%i==0){
		a.push_back(i);
		b.push_back(0);
		while(tmpn%i==0){
			b[b.size()-1]++;
			tmpn/=i;
		}
	}
	ll ret=1;
	for(int i=0;i<a.size();++i){
		int k=n;
		int res=b[i];
		for(int j=1;j<=b[i];++j){
			k/=a[i];
			if(!work(k,a[i])){
				res=j-1;
				break;
			}
		}
		for(int j=1;j<=b[i]-res;++j)ret*=a[i];
	}
	int r=0;
	for(int i=1;i<=n;++i)
	if(n%i==0&&i%ret==0){
		++r;
	}
	return r;
}

int main(){
	scanf("%d%d",&n,&m);
	int ansn=work();
	flag=1;
	swap(n,m);
	int ansm=work();
	printf("! %d\n",ansn*ansm);
}