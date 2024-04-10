#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=1010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
vector<int> ans;
string s;
int T;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>s;
		for(int i=0;i+2<s.length();i++){
			if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e'){
				//s[i+1]=' ';
				ans.push_back(i+1);
			}
			else if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o'){
				if(i+3<s.length() && s[i+3]=='o'){
					//s[i+1]=' ';
					ans.push_back(i+1);
				}
				else{
					s[i+2]=' ';
					ans.push_back(i+2);
				}
			}
		}
		cout<<ans.size()<<endl;
		for(auto i:ans)cout<<i+1<<' ';
		cout<<endl;
		ans.clear();
	}
    return 0;
}