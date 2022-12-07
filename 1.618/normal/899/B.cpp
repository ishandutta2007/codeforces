#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<sstream>
#include<ctime>
using namespace std;
const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int st[13];
bool no_leap[13];
int n,a[50],k=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=12;i++){
		if(day[i]==a[1]){
			st[++k]=i;
		}
	}
	if(a[1]==29){
		st[++k]=2;
		no_leap[k]=true;
	}
	for(int i=1;i<=k;i++){
		int cur=st[i];
		bool fl=0;
		for(int j=2;j<=n;j++){
			cur++;
			if(cur==13) cur=1;
			if(cur==2){
				if(a[j]==29&&no_leap[i]==0){
					no_leap[i]=true;
					continue;
				}
			}
			if(a[j]!=day[cur]){
				fl=1;
				break;
			}
		}
		if(fl==0){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}