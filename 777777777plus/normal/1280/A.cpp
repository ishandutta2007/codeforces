#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
const ll mod = 1e9+7;

int T;
int x,n;
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&x,s+1);
		n=strlen(s+1);
		ll r=n,R=n;
		for(int i=1;i<=x;++i){
			r=(r-1+mod)%mod;
			r=r*(s[i]-'0')%mod;
			int Rlast=R;
			for(int j=1;j<=s[i]-'1';++j){
				for(int k=i+1;k<=Rlast;++k){
					if(R>=x)break;
					s[++R]=s[k];
				}
			}
		}
		cout<<(r+x)%mod<<endl;
	}
}