#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int>p[3];
#define f first
#define s second
signed main(){//ios::sync_with_stdio(0),cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c,p[0]={a,1},p[1]={b,2},p[2]={c,3},sort(p,p+3);
	cout<<"First\n"<<(c=p[2].f*2-p[1].f-p[0].f)<<'\n',cin>>a;
	if(a^p[2].s){gg:;
		for(b=0;b<3;++b)if(p[b].s==a)p[b].f+=c;
		sort(p,p+3),cout<<p[2].f-p[1].f<<'\n',cin>>a,exit(0);
	}else{
		p[2].f+=c,cout<<(c=p[2].f*2-p[1].f-p[0].f)<<'\n',cin>>a;goto gg;
	}
	return 0;
}/*
456
457
579/4710/451*/