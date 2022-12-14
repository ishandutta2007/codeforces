#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 100010
#define inf 1e9
int T,n,a[256],f[256];
string s;
#define rem a['S']>0?'S':a['R']>0?'R':'P'
#define tra(c) c=='S'?'R':c=='R'?'P':'S'
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		mst(f,0); int ans=0;
		cin>>n;
		cin>>a['S']>>a['R']>>a['P'];
		cin>>s;
		repeat(i,0,s.length()){
			if(a[s[i]]>0){
				f[i]=true;
				a[s[i]]--;
				ans++;
			}
		}
		repeat(i,0,s.length()){
			if(!f[i]){
				char c=rem;
				a[c]--;
				s[i]=c;
			}
			s[i]=tra(s[i]);
		}
		if(ans>=(n+1)/2){
			cout<<"YES"<<endl;
			cout<<s<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}