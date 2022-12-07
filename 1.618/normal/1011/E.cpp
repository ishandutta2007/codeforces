#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <map>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a % b);
}
int n,k,a[100005];
vector <int> ans;
int main(){
	scanf("%d%d",&n,&k);
	int g = k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		g = gcd(g,a[i]);
	}
	for(int i=0;i<k;i += g){
		ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d%c",ans[i],i == ans.size()-1 ? '\n' : ' ');
	}
  return 0;
}