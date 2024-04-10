#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

int T,n; 
void solve() {
	int x,y; 
	cin>>x>>y; 
	if ((x+y)&1) puts("-1 -1"); 
	else {
		int X=min(x,(x+y)/2); 
		int Y=(x+y)/2-X;
		cout<<X<<' '<<Y<<'\n'; 
	}
}
int main() {
	scanf("%d",&T);
	while (T--) solve(); 
	return 0;
}