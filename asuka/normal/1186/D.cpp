#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define eps 1e-6
using namespace std;
int n,pos,neg,ok[N];
double t[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		scanf("%lf",&t[i]);
		if(1.0*t[i]-1.0*(floor(t[i])) < eps) ok[i] = 0;
		else{
			if(t[i]>0) ok[i] = 1;
			else ok[i] = -1;
		}
		
		if(t[i]>0) pos+=(int)floor(t[i]);
		else neg-=(int)floor(t[i]);
	//	cout << floor(t[i]) << endl;
	}
	//cout << pos << ' ' << neg << endl;
	for(int i = 1;i <= n;++i){
		if(ok[i]==0){
			printf("%d\n",(int)floor(t[i]));
			continue;
		}
		if(pos<neg){
			printf("%d\n",(int)floor(t[i]+1));
			pos++; 
		}else{
			printf("%d\n",(int)floor(t[i]));
		}
	}
	return 0;
}