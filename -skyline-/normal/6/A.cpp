#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
int a[5],ans;
int go(int x,int y,int z){
	if(a[x]+a[y]>a[z]) return 2;
	if(a[x]+a[y]==a[z]) return 1;
	return 0;
}
int main(){
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	sort(a+1,a+5);
	ans=max(ans,go(1,2,3));
	ans=max(ans,go(1,2,4));
	ans=max(ans,go(1,3,4));
	ans=max(ans,go(2,3,4));
	if(ans==2)puts("TRIANGLE");
	if(ans==1)puts("SEGMENT");
	if(ans==0)puts("IMPOSSIBLE");
	return 0;
}