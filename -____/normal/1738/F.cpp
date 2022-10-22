#include<bits/stdc++.h>
using namespace std;
const int N = 1111;
int n,d[N],f[N],u[N];
pair<int,int> p[N];
int fnd(int x){
	if(x==f[x])
		return x;
	return f[x]=fnd(f[x]);
}
int main(){
	int T,i,j,x,y;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>d[i];
			p[i]=make_pair(d[i],i);
			f[i]=i;
			u[i]=0;
		}
		sort(p+1,p+n+1);
		for(i=n;i>=1;i--){
			x=p[i].second;
			if(u[x])
				continue;
			u[x]=1;
			for(j=1;j<=d[x];j++){
				cout<<"? "<<x<<endl;
				cin>>y;
				if(u[y]){
					f[fnd(x)]=fnd(y);
					break;
				}
				f[y]=x;
				u[y]=1;
			}
		}
		cout<<"! ";
		for(i=1;i<=n;i++)
			cout<<fnd(i)<<' ';
		cout<<endl;
	}
	return 0;
}