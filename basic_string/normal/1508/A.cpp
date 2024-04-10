#include<bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
string ss[3],s;
int n;
void work(string&u,string&v,int w){
	s=u.substr(0,w);
	int t=0,i;
	for(i=0;i<s.size();++i){
		if(v[t]==s[i])++t;
	}
	s+=v.substr(t);
	t=0;
	for(i=0;i<s.size();++i){
		if(t<u.size()&&u[t]==s[i])++t;
	}
	s+=u.substr(t);
}
int a[3]={0,1,2};
int main(){
	int T=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cin>>ss[0]>>ss[1]>>ss[2];
		while(1){
			random_shuffle(a,a+3);
			work(ss[a[0]],ss[a[1]],rd()%(n*2+1));
			if(s.size()<=3*n)break;
		}cout<<s<<'\n';
	}
	return 0;
}