#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+5;

int n,m,a[N];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		a[i]=i;
		m-=(i-1)/2;
		if(m<=0){
			while(m<0){
				m++;
				a[i]+=2;
			}
			for(int j=i+1;j<=n;++j)a[j]=a[j-1]+a[i]+1;
			for(int j=1;j<=n;++j)cout<<a[j]<<" ";
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}