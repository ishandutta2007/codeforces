#include<bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

const int L=20;
const int N=1e5+5;
const int mod=1e9+7;

int n,size,a[N],pw[N];
int cnt,rev[75],lab[75];
bool canxor(int val){
	for(int i=19;~i;i--)if(val>>i&1)val^=a[i];
	return val==0;
}
void insert(int x){
	for(int i=19;~i;i--)
		if(x>>i&1){
			if(a[i]){x^=a[i]; continue;}
			for(int j=i-1;~j;j--)if(x>>j&1)x^=a[j];
			for(int j=i+1;j<20;j++)if(a[j]>>i&1)a[j]^=x;
			return a[i]=x,size++,void();
		}
}

int main(){
	for(int i=2;i<=70;i++){
		bool isp=1;
		for(int j=2;j<i;j++)isp&=i%j!=0;
		if(isp)rev[i]=cnt,cnt++;
	}
	for(int i=1,tmp=1;i<=70;tmp=++i)
		for(int j=2;j<=tmp;j++)
			if(tmp%j==0){
				bool fl=0;
				while(tmp%j==0)tmp/=j,fl^=1;
				lab[i]|=fl<<rev[j];
			}
	cin>>n,pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1,x;i<=n;i++)cin>>x,insert(lab[x]);
	cout<<pw[n-size]-1<<endl;
	return 0;
}
////