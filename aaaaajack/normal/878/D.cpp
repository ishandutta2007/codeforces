#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[12][N];
bitset<4096> table[N];
int main(){
	int n,k,q,tp,x,y,num;
	scanf("%d%d%d",&n,&k,&q);
	num=k;
	for(int i=0;i<k;i++){
		for(int j=0;j<(1<<k);j++){
			if(j&(1<<i)) table[i+1].set(j);
		}
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&tp,&x,&y);
		if(tp<3){
			++num;
			if(tp==1) table[num]=table[x]&table[y];
			else table[num]=table[x]|table[y];
		}
		else{
			pair<int,int> p[12];
			for(int j=0;j<k;j++){
				p[j].first=a[j][y-1];
				p[j].second=j;
			}
			sort(p,p+k);
			int now=0;
			for(int j=0;j<k;j++){
				now|=1<<p[j].second;
				if(table[x][now]){
					printf("%d\n",p[j].first);
					break;
				}
			}
		}
	}
	return 0;
}