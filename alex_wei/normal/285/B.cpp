#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,s,t,cnt,p[N],q[N];
int main(){
	cin>>n>>s>>t;
	for(int i=1;i<=n;i++)cin>>p[i];
	while(s!=t&&!q[s]){
		q[s]=1;
		cnt++;
		s=p[s];
	}
	if(q[s])puts("-1");
	else cout<<cnt<<endl;
	return 0;
}