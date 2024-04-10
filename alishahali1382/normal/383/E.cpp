#include <bits/stdc++.h>
#pragma GCC optimize ("O2")

using namespace std;

int n, ans;
int val[1<<24];
char c1, c2, c3;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>c1>>c2>>c3;
		val[(1<<(c1-'a'))|(1<<(c2-'a'))|(1<<(c3-'a'))]++;
	}
	for (int i=0; i<24; i++) for (int j=0; j<(1<<24); j++) if (j&(1<<i)) val[j]+=val[j-(1<<i)];
	for (int i=0; i<(1<<24); i++) val[i]=n-val[i], ans^=val[i]*val[i];
	cout<<ans<<'\n';
	
	return 0;
}