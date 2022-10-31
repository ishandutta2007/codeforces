#include<bits/stdc++.h>
#define N 300100
using namespace std;
list<int> a[N];
int cnt[N];
bool rd[N];
int main(){
	int n,q,mx=0,tp,now=0,ans=0,x;
	scanf("%d%d",&n,&q);
	while(q--){
		scanf("%d%d",&tp,&x);
		if(tp==1){
			ans++;
			a[x].push_back(++now);
		}
		else if(tp==2){
			while(!a[x].empty()){
				if(!rd[a[x].back()]){
					rd[a[x].back()]=true;
					ans--;
				}
				a[x].pop_back();
			}
		}
		else{
			while(mx<x){
				++mx;
				if(!rd[mx]){
					rd[mx]=true;
					ans--;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}