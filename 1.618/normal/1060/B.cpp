#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair

using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
ll n;
int a[25],k,ans;
int main(){
	scanf("%I64d",&n);
	while(n){
		a[++k] = n % 10;
		ans += a[k];
		n /= 10;
	}
	bool all9 = true;
	for(int i=1;i<k;i++){
		if(a[i] != 9) all9 = false;
		if(!all9) ans += 9;
	}
	printf("%d\n",ans);
	return 0;
}