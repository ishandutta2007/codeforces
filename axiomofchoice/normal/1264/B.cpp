#include <bits/stdc++.h>
using namespace std;
using ll=long long; //using lll=__int128;
using pii=pair<int,int>;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=100010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
vector<int> ans;
int in[5],s[5];
void init(){
	repeat(i,0,4)s[i]=in[i];
	ans.clear();
}
void OK(){
	cout<<"YES"<<endl;
	repeat(i,0,ans.size())
		cout<<ans[i]<<' ';
	cout<<endl;
	exit(0);
}
void push(int a){
	ans.push_back(a); s[a]--;
}
void workb1(int a,int b,int c,int d){
	if(s[c]+s[d]==0 && s[a]==s[b]+1){
		while(s[b]!=0){
			push(a);
			push(b);
		}
		push(a);
		OK();
	}
	if(s[c]+s[d]==0 && s[a]==s[b]){
		while(s[b]!=0){
			push(a);
			push(b);
		}
		OK();
	}
	if(s[a]+s[b]+s[c]+s[d]==0)OK();
	if(s[a]==0)return;
	if(s[a]<s[b]){
		while(s[a]!=1){
			push(a);
			push(b);
		}
		push(a);
		workb1(b,c,d,4);
	}
	if(s[a]==s[b]){
		while(s[a]!=0){
			push(a);
			push(b);
		}
		workb1(c,d,4,4);
	}
}
void work2(int a,int b,int c,int d){
	init();
	if(s[b]){
		push(b);
		workb1(a,b,c,d);
	}
	init();
	if(s[b] && s[d]==0){
		push(b);
		workb1(c,b,a,4);
	}
	init();
	if(s[b] && s[c]){
		push(b); push(c);
		workb1(d,c,b,a);
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	repeat(i,0,4)cin>>in[i];
	init(); workb1(0,1,2,3);
	init(); workb1(3,2,1,0);
	work2(0,1,2,3);
	work2(3,2,1,0);
	cout<<"NO"<<endl;
	return 0;
}