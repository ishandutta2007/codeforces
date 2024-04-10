#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 100005
using namespace std;
typedef long long ll;
int n,a[maxn];
bool check(int x){
	for(int i=1;i<=x;i++){
		if(a[i] >= a[i+n-x]) return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int lb = 0,rb = n;
	while(lb < rb){
		int mid = (lb + rb + 1) >> 1;
		if(check(mid)) lb = mid;
		else rb = mid - 1;
	}
	printf("%d\n",lb);
	return 0;
}