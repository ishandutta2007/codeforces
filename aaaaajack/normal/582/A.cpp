#include<cstdio>
#include<algorithm>
#include<set>
#define N 510
#define S 35000
using namespace std;
int a[N*N],b[N];
int gcd(int x,int y){
	while(y){
		x%=y;
		x^=y,y^=x,x^=y;
	}
	return x;
}
int main(){
	multiset<int> f;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n*n;i++) scanf("%d",&a[i]),f.insert(a[i]);
	for(int i=0;i<n;i++){
		b[i]=*f.rbegin();
		f.erase(f.find(b[i]));
		for(int j=0;j<i;j++){
			int tmp=gcd(b[j],b[i]);
			f.erase(f.find(tmp));
			f.erase(f.find(tmp));
		}
	}
	for(int i=0;i<n;i++) printf("%d ",b[i]);
	return 0;
}