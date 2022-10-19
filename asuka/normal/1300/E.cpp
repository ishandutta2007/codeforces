#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#define ll long long
#define N 1000015
using namespace std;
int n,a[N],ri[N];
double ave[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;++i) scanf("%d",&a[i]);
	for(int i = 1;i <= n;++i) ri[i] = i,ave[i] = a[i];
	for(int i = n;i > 0;--i){
		if(i!=n){
			for(int j = i;j <= n;j = ri[j+1]){
				if(ave[j+1] <= ave[i]&&j != n){
					ri[i] = ri[j+1];
					ave[i] = (1.0*(1.0*ave[j+1]*(1.0*ri[j+1]-j)+1.0*(1.0*j-i+1)*ave[i]))/(double(1.0*ri[i]-i+1));
				//	printf("%d %.9lf\n",j+1,ave[j+1]);
				}else{
					break;
				}
			}
		}
		//printf("Yes %d %.9lf\n",ri[i],ave[i]);
	}
	for(int r,i = 1;i <= n;i=r+1){
		r = ri[i];
		for(int j = i;j <= r;++j){
			printf("%.9lf\n",ave[i]);
		}
	}
    return 0;
}
/*
8
3213 323 7657 32 43 321 465 21
*/