#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1e6+1;
int a[maxn],c,nn=1,n,b[maxn];
vector<int>ans;
int main(){
	cin>>n;
	a[0]=1;
	b[1]=0;
	for(int i=0;i<n;i++){
		cin>>c;
		if(b[a[c]]==c){
			b[a[c]]=i+1;
			a[i+1]=a[c];
		}else{
			nn++;
			b[nn]=i+1;
			a[i+1]=nn;
		}
	}
	cout<<nn;
}