#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef long long lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=100010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
string s,s1;
int n,k;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	cin>>s; s1=s;
	repeat(i,0,n)
	if(i>=k)
		s1[i]=s1[i-k];
	if(s1<s){
		int p=k-1;
		s1[p]++;
		while(s1[p]-'0'==10){
			s1[p-1]++;
			s1[p]='0';
			p--;
		}
	}
	cout<<n<<endl;
	repeat(i,0,n)
	if(i>=k)
		s1[i]=s1[i-k];
	cout<<s1<<endl;
	return 0;
}