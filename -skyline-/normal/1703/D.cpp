#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int T,n;
string s[100005];
ll l[100005][10],r[100005][10];
set<ll> S;
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		S.clear();
		for(int i=1;i<=n;++i){
			cin>>s[i];
			ll o=0;
			for(int j=0;j<s[i].size();++j){
				o=o*30ll+s[i][j]-96;
				l[i][j]=o;
			}
			S.insert(o);
			o=0;
			ll p=1;
			for(int j=(int)s[i].size()-1;j>=0;--j){
				o=o+(s[i][j]-96)*p;
				p=p*30ll;
				r[i][j]=o;
			}
		}
		for(int i=1;i<=n;++i){
			int ok=0;
			for(int j=1;j<s[i].size();++j)if(S.count(l[i][j-1])&&S.count(r[i][j]))ok=1;
			printf("%d",ok);
		}
		printf("\n");
	}
    return 0;
}