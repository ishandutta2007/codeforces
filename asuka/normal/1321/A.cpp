#include<bits/stdc++.h>
#define ll long long
#define N 115
using namespace std;
int n,a[N],b[N],acnt,bcnt; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;++i) scanf("%d",&a[i]);
	for(int i = 1;i <= n;++i) scanf("%d",&b[i]);
	for(int i = 1;i <= n;++i){
		if(a[i]==1&&b[i]==1)
			continue;
		if(a[i]==1) acnt++;
		if(b[i]==1) bcnt++;
	}
	if(acnt==0){
		puts("-1");
		return 0;
	}
	bcnt++;
	cout << ((bcnt+acnt-1)/acnt) << endl;
	return 0;
}