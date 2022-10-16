#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,c,t;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		int ans=1e9;
		int xx,yy,zz;
		for(int i=1;i<=1.5e4;i++){
			int aa,bb=i,cc;
			int tmp=abs(b-i);
			int ca=1e9,mx=sqrt(i);
			for(int j=1;j<=mx;j++)
				if(i%j==0){
					if(abs(a-j)<ca)aa=j;
					ca=min(ca,abs(a-j));
					if(abs(a-i/j)<ca)aa=i/j;
					ca=min(ca,abs(a-i/j));
				}
			tmp+=ca,ca=1e9;
			for(int j=i;j<=3e4;j+=i){
				if(abs(c-j)<ca)cc=j;
				ca=min(ca,abs(c-j));
			}
			if(tmp+ca<ans)xx=aa,yy=bb,zz=cc,ans=tmp+ca;
		}
		cout<<ans<<endl<<xx<<" "<<yy<<" "<<zz<<endl;
	}
	return 0;
}