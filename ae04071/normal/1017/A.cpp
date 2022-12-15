#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

pii arr[1000];
int n;

int main() {
	int val;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<4;j++) {
			scanf("%d",&val);
			arr[i].first += val;	
		}
		arr[i].second = i;
		
	}
	sort(arr,arr+n,[](const pii &a,const pii &b){
		return a.first!=b.first ? a.first>b.first : a.second<b.second;
	});
	for(int i=0;i<n;i++) if(arr[i].second==0){
		printf("%d\n",i+1);
		break;
	}
	return 0;
}