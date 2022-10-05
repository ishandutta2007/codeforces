#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
const int maxn=1e5+123;
int n,a,b;
bool check(int x){
	int res=0;
	res+=a/x+b/x;
	if(res>=n)
		return true;
	return false;
}
int main(){                                                  
	cin>>n>>a>>b;
	int l=1,r=min(a,b);
	while(l<=r){
		int m=(l+r)/2;
		if(check(m))
			l=m+1;
		else
			r=m-1;
	}
	cout<<l-1;
}