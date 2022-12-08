#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int T;
int n,k;
string s;
vector<int> g[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		cin>>s;
		for(int i=0;i<k;++i){
			g[i].clear();
		}
		for(int i=0;i<n;++i){
			g[i%k].push_back(i);
		}
		bool flag=1;
		for(int i=0;i<k;++i){
			bool a=0;
			bool b=0;
			for(int j=0;j<g[i].size();++j){
				a|=s[g[i][j]]=='0';
				b|=s[g[i][j]]=='1';
			}
			if(a&b){
				flag=0;
				break;
			}
			else if(a||b){
				for(int j=0;j<g[i].size();++j){
					s[g[i][j]]=a?'0':'1';
				}
			}
		}
		if(!flag){
			puts("NO");
			continue;
		}
		for(int i=0,r=0;i<k;i=++r){
			while(r+1<i+k)++r;
			int c0=0,c1=0;
			for(int j=i;j<=r;++j)
			if(s[j]=='0')c0++;
			else if(s[j]=='1')c1++;
			if(c0>k/2||c1>k/2){
				flag=0;
				break;
			}
		}
		if(flag){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
}