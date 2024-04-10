#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3)
const int N=3e5+5;
const int K=6e2+5;
int n,m,a[N],mi[N],mx[N],in[N];
deque <int> q[K];
int cal(int pos){
	return (pos-1)/K;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i],mi[a[i]]=1;
	for(int i=1;i<=n;i++){
		mx[i]=i;
		if(mi[i]!=1)mi[i]=i;
		int pos=cal(i);
		in[i]=pos;
		q[pos].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int j=in[a[i]];
		int len=q[j].size(),p=j*K,pos=0;
		for(int k=0;k<len;k++)
			if(q[j][k]==a[i]){
				pos=k;
				q[j].erase(q[j].begin()+k);
				break;
			}
		in[a[i]]=0;
		q[0].push_front(a[i]);
		for(int k=0;k<j;k++){
			int z=q[k].back();
			in[z]++;
			q[k].pop_back();
			q[k+1].push_front(z);
		}
		mx[a[i]]=max(mx[a[i]],p+pos+1);
	}
	int cnt=1;
	for(int i=0;i<=cal(n);i++)
		for(int j=0;j<q[i].size();j++,cnt++)
			mx[q[i][j]]=max(mx[q[i][j]],cnt);
	for(int i=1;i<=n;i++)
		cout<<mi[i]<<" "<<mx[i]<<endl;
    return 0;
}