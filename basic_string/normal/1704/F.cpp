#include<bits/stdc++.h>
using namespace std;
int f[100009],g[100009];
basic_string<int>bs[199999];

	char s[500009];
bool b[199999];//f:rbrb g:brbr
int get(int x){
	if(x<=555)return f[x];
	return f[x%34+340];
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
bs[0]+=0,bs[0]+=1;
	for(int i=2;i<=1000;++i){
		memset(b,0,sizeof b);
		for(int j=0;j<=i-2;++j){
			b[f[j]^f[i-j-2]]=1;
		}
		for(int j=0;;++j)if(!b[j]){f[i]=j;break;}
		//cout<<i<<' '<<f[i]<<'!'<<'\n';
		bs[f[i]]+=i;
	}
	int T,n,m,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		cin>>(s+1);
		int cb=0,cr=0;
		for(i=1;i<=n;++i){
			if(s[i]=='B')++cb;else ++cr;
		}
		if(cr>cb)cout<<"Alice\n";
		else if(cr<cb)cout<<"Bob\n";
		else{
			int ans=0,len=0;
			for(i=1;i<=n;++i){
				if(s[i]==s[i-1])ans^=get(len),len=0;
				++len;
			}
			ans^=get(len);
			if(ans)cout<<"Alice\n";else cout<<"Bob\n";
		}
	}
	/*for(int i=0;i<=100099;++i)if(bs[i].size()){
		cout<<i<<' '<<bs[i].size()<<'\n';;
	//	for(int o:bs[i])cout<<o<<' ';cout<<'\n';
	}*/
	/*int T,n,m,i,j,k;
	for(cin>>T;T--;){
		
	}*/
}/*
rrbrbrr 
bbrbrbb
rrbrbb
bbrbrr
rrbrbrbrr*/