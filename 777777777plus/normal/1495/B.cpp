#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+5;

int n,a[N];
int l[N],r[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	l[1]=0;
	for(int i=2;i<=n;++i){
		if(a[i-1]<a[i])l[i]=l[i-1]+1;
		else l[i]=0;
	}
	r[n]=0;
	for(int i=n-1;i;--i){
		if(a[i+1]<a[i])r[i]=r[i+1]+1;
		else r[i]=0;
	}
	int mx=max(*max_element(l+1,l+n+1),*max_element(r+1,r+n+1));
	int cnt=0;
	for(int i=1;i<=n;++i)if(max(l[i],r[i])==mx)cnt++;
	if(cnt>1||mx%2)return 0*puts("0");
	for(int i=1;i<=n;++i)
	if(l[i]==r[i]&&r[i]==mx){
		puts("1");
		return 0;
	}
	puts("0");
}
/*
2 2
1 1
1 1 1 2
1 1 1 2
8 3
4 2 2 1 2 2 4 4
1 3 1 2
2 4 4
1 2 9 2

7 5
1 1 2 2 3 3 1
2 4 4
2 5 2
2 6 6
1 5 2 9
1 5 2 9
*/