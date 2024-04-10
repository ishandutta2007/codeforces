#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef long long lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=200010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
int c[26],c1[26];
string s,s1;
int T;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>s1>>s; int len1=s1.size(),len=s.size();
		mst(c1,0);
		repeat(i,0,len1)
			c1[s1[i]-'a']++;
		bool f=false;
		repeat(i,len1,len+1){
			mst(c,0);
			repeat(j,i-len1,i){
				c[s[j]-'a']++;
			}
			f=true;
			repeat(j,0,26)
			if(c[j]!=c1[j])
				f=false;
			if(f)break;
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}