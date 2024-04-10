#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e3+5;
int n,m,d[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>d[i];
	sort(d+1,d+m+1);
	if(d[1]==1||d[m]==n)puts("NO"),exit(0);
	for(int i=3;i<=m;i++)if(d[i]==d[i-1]+1&&d[i-1]==d[i-2]+1)puts("NO"),exit(0);
	puts("YES");
    return 0;
}