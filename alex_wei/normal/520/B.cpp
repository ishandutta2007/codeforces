#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,q[N];
queue <int> z;
int main(){
	cin>>n>>m; z.push(n);
	memset(q,0x3f,sizeof(q)); q[n]=0;
	while(!z.empty()){
		int t=z.front(); z.pop();;
		if(t*2<N&&q[t*2]>1e9)q[t*2]=q[t]+1,z.push(t*2);
		if(t-1>0&&q[t-1]>1e9)q[t-1]=q[t]+1,z.push(t-1);
	}
	cout<<q[m]<<endl;
	return 0;
}