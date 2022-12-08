#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n;
int a[N],l[45],r[45];
int ans=2e9;

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<n;++i){
		l[0]=a[i];
		r[0]=a[i+1];
		int s1=0,s2=0;
		for(int j=1;j<=40;++j){
			if(i-j<0)break;
			++s1;
			l[j]=l[j-1]^a[i-j];
		}
		for(int j=1;j<=40;++j){
			if(i+1+j>n)break;
			++s2;
			r[j]=r[j-1]^a[i+j+1];
		}
		for(int i=0;i<=s1;++i)
		for(int j=0;j<=s2;++j)
		if(l[i]>r[j]){
			ans=min(ans,i+j);
		}
	}
	if(ans==2e9)puts("-1");
	else printf("%d\n",ans);
}