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
int cnt[256];
int T;
string s;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		mst(cnt,0);
		cin>>s;
		for(auto i:s)cnt[i]++;
		int DU=min(cnt['D'],cnt['U']);
		int LR=min(cnt['L'],cnt['R']);
		if(DU==0)LR=min(1,LR);
		if(LR==0)DU=min(1,DU);
		cout<<2*(DU+LR)<<endl;
		repeat(i,0,DU)cout<<'D';
		repeat(i,0,LR)cout<<'L';
		repeat(i,0,DU)cout<<'U';
		repeat(i,0,LR)cout<<'R';
		cout<<endl;
	}
    return 0;
}