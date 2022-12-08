#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int a,b,c;

int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
		int ans=0;
		if(a)a--,ans++;
		if(b)b--,ans++;
		if(c)c--,ans++;
		int d[3];
		d[0]=a;d[1]=b;d[2]=c;
		sort(d,d+3);
		if(d[0]>=3&&d[1]>=3&&d[2]>=3)ans+=4;
		else if(d[0]>=2&&d[1]>=2&&d[2]>=2)ans+=3;
		else if(d[0]>=1&&d[1]>=1&&d[2]>=2)ans+=2;
		else if(d[1]>=1&&d[2]>=1)ans+=1;
		cout<<ans<<endl;
	}
}