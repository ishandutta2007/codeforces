#include <iostream>
#include <algorithm>
#include <cmath>
int n,m,l[100],r[100],a[100],b[100],len,q;
using namespace std;
void add(){
		int bl=l[q]/len,br=r[q]/len;
		if(bl==br){
			for(int i=l[q];i<=r[q];i++){
				a[i-1]++;
			}
			return ;
		}else{
		for(int i=bl+1;i<br;i++){
			b[i]++;
		}
		for(int i=l[q];i<=(bl+1)*len;i++){
			a[i-1]++;
		}
		for(int i=br*len;i<r[q];i++){
			a[i]++;
		}
		}
		return ;
}
int main(){
	cin>>n>>m;
	len=sqrt(n)+1;
	for(int i=0;i<n;i++){
		a[i]=0;b[i]=0;
	}
	for(q=0;q<m;q++){
		cin>>l[q]>>r[q];	
		add();
	}
	for(int i=0;i<n;i++){
		if(a[i]+b[i/len]!=1){
			cout<<i+1<<" "<<a[i]+b[i/len];return 0;
		}
	}
	cout<<"OK";
	return 0;
}