#include<bits/stdc++.h>
#define R(x) rand()*rand()%x+1
using namespace std;
int n,m,x,y,z,now,k;
int main(){
//	freopen("1.in","r",stdin);
	register int i;scanf("%d%d",&n,&k);srand(time(0));
	for(i=1;i<=350;i++) cout<<"? "<<R(n)<<endl,cin>>x;
	while(1){
		now=R(n);cout<<"? "<<now<<endl;cin>>y;
		if(y^k) break;
	}
	if(y>k){
		while(1){
			now=(now-2+n)%n+1;cout<<"? "<<now<<endl;cin>>x;
			if(x==k) break;
		}
	}
	else{
		while(1){
			now=now%n+1;cout<<"? "<<now<<endl;cin>>x;
			if(x==k) break;
		}
	}
	cout<<"! "<<now<<endl;
}