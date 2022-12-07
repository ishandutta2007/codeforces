#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <map>

using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef map<int,int>::iterator Ite;
int n;
map <int,int> mp;
int cnt;
void fctrize(int x){
	for(int i=2;i * i <= x;i++){
		if(x % i == 0){
			while(x % i == 0){
				mp[i]++;
				x /= i;
			}
		}
	}
	if(x != 1) mp[x]++;
}
void check(int x){
	int res = 0,i;
	for(i=1;i<x;i <<= 1) res++;
	cnt = max(res,cnt);
}
int main(){
	scanf("%d",&n);
	fctrize(n);
	int m = 1;
	for(Ite it = mp.begin();it != mp.end();it++){
		check(it -> second);
		m *= it -> first;
	}
	for(Ite it = mp.begin();it != mp.end();it++){
		if(it -> second != (1 << cnt)){
			cnt++;
			break;
		}
	}
	printf("%d %d\n",m,cnt);
	return 0;
}