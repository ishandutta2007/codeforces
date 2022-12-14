#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
string s,t;
set<char> ss;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		cin>>s>>t;
		ss.clear();
		bool f=false;
		repeat(i,0,s.length()){
			ss.insert(s[i]);
		}
		repeat(i,0,t.length()){
			if(ss.count(t[i])){f=true;break;}
		}
		if(f)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}