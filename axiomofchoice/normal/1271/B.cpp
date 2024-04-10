#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=200010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
vector<int> ans;
string s,t;
int n;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	cin>>s; t=s;
	repeat(i,0,s.length()-1){
		if(s[i]=='W')
			s[i+1]='W'+'B'-s[i+1],ans.push_back(i);
	}
	if(s[s.length()-1]=='W'){
		s=t; ans.clear();
		repeat(i,0,s.length()-1){
			if(s[i]=='B')
				s[i+1]='W'+'B'-s[i+1],ans.push_back(i);
		}
		if(s[s.length()-1]=='B')
			cout<<-1<<endl;
		else{
			cout<<ans.size()<<endl;
			repeat(i,0,ans.size())
				cout<<ans[i]+1<<' ';cout<<endl;
		}
	}
	else{
		cout<<ans.size()<<endl;
		repeat(i,0,ans.size())
			cout<<ans[i]+1<<' ';cout<<endl;
	}
    return 0;
}