#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=5010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
int n;
string s;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	while(n--){
		cin>>s;
		bool f=false,f0=false;
		int sum=0;
		repeat(i,0,s.size()){
			if(!f0 && s[i]=='0'){
				f0=true;
				continue;
			}
			sum+=s[i]-'0';
			if((s[i]-'0')%2==0)f=true;
		}
		if(sum%3==0 && f && f0)
			cout<<"red"<<endl;
		else
			cout<<"cyan"<<endl;
	}
    return 0;
}