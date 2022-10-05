#include<bits/stdc++.h>
using namespace std;
enum{N=1000009};
int n,z[N],z2[N],p[N],p2[N];
string a,b,ra;
void zfunc(string&a,string&b){
	int i,l,r;
	for(z[0]=n,i=1,a+=1,b+=2,l=r=0;i<n;++i){
		if(i<=r)z[i]=min(z[i-l],r-i+1);
		while(b[i+z[i]]==b[z[i]])++z[i];
		if(i+z[i]-1>r)r=i+z[i]-1,l=i;
	}
	for(i=0,l=r=-1;i<n;++i){
		if(i<=r)z2[i]=min(z[i-l],r-i+1);
		while(a[i+z2[i]]==b[z2[i]])++z2[i];
		if(i+z2[i]-1>r)r=i+z2[i]-1,l=i;
	}
}
void kmp(string&a,string&b){
	int i,j;
	for(i=1,j=0;i<n;++i){
		while(j&&b[i]!=b[j])j=p[j-1];
		if(b[i]==b[j])p[i]=++j;
	}
	for(i=j=0;i<n;++i){
		while(j&&a[i]!=b[j])j=p[j-1];
		if(a[i]==b[j])p2[i]=++j;
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int ai=-1,aj=-1,i,j;
	if(getline(cin,a),getline(cin,b),n=a.size(),n!=b.size())return cout<<"-1 -1",0;
	ra=a,reverse(begin(ra),end(ra));
	zfunc(a,b),kmp(b,ra);
	for(i=0;i<n-1&&a[i]==b[n-i-1];++i){
		j=n-p2[n-i-2];
		if(z2[i+1]>=j-i-1)ai=i,aj=j;
	}
	cout<<ai<<' '<<aj;
	return 0;
}