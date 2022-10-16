#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5,K=333;
deque <int> d[K];
int buc[K][N],ans,n,q;
int cal(int x){
	return (x-1)/K;
}
int pos(int x){
	return (x-1)%K;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int id=cal(i);
		d[id].push_back(x);
		buc[id][x]++;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int op,l,r;
		cin>>op>>l>>r;
		l=(l+ans-1)%n+1,r=(r+ans-1)%n+1;
		if(l>r)swap(l,r);
		if(op==1){
			int idl=cal(l),idr=cal(r),pl=pos(l),pr=pos(r);
			int val=d[idr][pr];
			d[idr].erase(d[idr].begin()+pr);
			buc[idr][val]--;
			d[idl].insert(d[idl].begin()+pl,val);
			buc[idl][val]++;
			for(int j=idl;j<idr;j++){
				val=d[j].back();
				d[j].pop_back();
				buc[j][val]--;
				d[j+1].push_front(val);
				buc[j+1][val]++;
			}
		}
		else{
			int k,idl=cal(l),idr=cal(r),pl=pos(l),pr=pos(r);
			cin>>k;
			k=(k+ans-1)%n+1;
			ans=0;
			if(idl==idr)for(int j=pl;j<=pr;j++)ans+=d[idl][j]==k;
			else{
				for(int j=pl;j<K;j++)ans+=d[idl][j]==k;
				for(int j=0;j<=pr;j++)ans+=d[idr][j]==k;
				for(int j=idl+1;j<idr;j++)ans+=buc[j][k];
			}
			printf("%d\n",ans);
		}
	}
    return 0;
}