#include<bits/stdc++.h>
using namespace std;
const int N=1e5+33;
long long s[200],ans,p[200],z;
int t,n;
long long a[N],b[N],c[N];
int main(){
	//freopen("p.in","r",stdin);
	cin>>t;
	for(int xx=1;xx<=t;xx++){
		cin>>n;
		for(int i=1;i<=n;i++){
			char c;
			cin>>c;
			a[i]=c-'0';
		}
		cout<<1;b[1]=a[1]+1;
		for(int i=2;i<=n;i++){
			if(b[i-1]!=a[i]+1){
				b[i]=a[i]+1;
				cout<<1;
			}else{b[i]=a[i];cout<<0;}
		}
		cout<<endl;
	}
	return 0;
}