#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
ll u,v;
vector<int> g[N];


int b(int x){
	int c=0;
	while(x){
	//	cout<<(x&1);
		c+=x&1;
		x/=2;
	}
	return c;
}

bool com(int x,int y){
	if(x>y)return 0;
	vector<int>a,b;
	for(int i=0;;++i){
		if(x&1)a.push_back(i);
		x/=2;
		if(!x)break;
	}
	x=y;
	for(int i=0;;++i){
		if(x&1)b.push_back(i);
		x/=2;
		if(!x)break;
	}
	if(a.size()<b.size())return 0;
	for(int i=0;i<b.size();++i)
	if(a[i]>b[i])return 0;
	return 1;
}

int main(){
	cin>>T;
	while(T--){
		scanf("%lld%lld",&u,&v);
		puts(com(u,v)?"YES":"NO");
	}
}