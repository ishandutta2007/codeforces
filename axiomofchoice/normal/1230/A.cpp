#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
	for(int i=(a),i##end=(b);i<i##end;i++)
#define mst(a,x) memset(a,x,sizeof(a))
int a[10];
bool work(){
	if(a[0]+a[3]==a[1]+a[2])return true;
	if(a[3]==a[1]+a[2]+a[0])return true;
	return false;
}
int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	repeat(i,0,4)cin>>a[i];
	sort(a,a+4);
	if(work())cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}