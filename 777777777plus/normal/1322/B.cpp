#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7+5;
const int M = 4e5+5;

int n;
int b[26];
int a[M],w[M][26];
int ans;

struct BIT{
	bool a[N];
	void add(int x){
		x++;
		for(;x<N;x+=x&-x)a[x]^=1;
	}
	bool sum(int x){
		x++;
		bool r=0;
		for(;x;x-=x&-x)r^=a[x];
		return r;
	}
	bool sum(int l,int r){
		if(r<l||r<0||l>1e7)return 0;
		l=max(l,0);l=min(l,10000000);
		r=min(r,10000000);
		return sum(r)^sum(l-1);
	}
}B;

int main(){
	scanf("%d",&n);
	b[0]=1;
	for(int i=1;i<26;++i)b[i]=b[i-1]*2;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for(int j=0;j<26;++j){
			w[i][j]=a[i]%b[j];
		}
	}
	for(int j=0;j<25;++j){
		int c=0;
		for(int i=1;i<=n;++i){
			int val=w[i][j+1];
			int l=b[j],r=b[j+1]-1;
			c^=B.sum(l-val,r-val);
			l+=b[j+1];r+=b[j+1];
			c^=B.sum(l-val,r-val);
			B.add(w[i][j+1]);
		}
		for(int i=1;i<=n;++i)B.add(w[i][j+1]);
		if(c)ans^=1<<j;
	}
	cout<<ans<<endl;
}