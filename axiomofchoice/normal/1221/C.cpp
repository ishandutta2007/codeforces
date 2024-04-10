#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
	for(int i=(a),i##end=(b);i<i##end;i++)
int a,b,c,N,ans,n;
int main(){
	//ios_base::sync_with_stdio(false);\
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	while(N--){
		cin>>a>>b>>c;
		if(a>b)swap(a,b);
		c+=b-a;
		b=a;
		ans=0;
		n=min(a,c);
		a-=n,b-=n,c-=n,ans+=n;
		cout<<ans+(a/3)*2+(a%3==2)<<endl;
	}
	return 0;
}