#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=110;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
char s[N][N];
bool lr[N],ud[N],haslr[N],hasud[N];
int T,n,m;
#define f(x,y) (s[x][y]=='A')
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		repeat(i,0,n){
			cin>>s[i];
		}
		repeat(i,0,max(n,m))
			lr[i]=ud[i]=true,haslr[i]=hasud[i]=false;
		bool has,ok;
		ok=true;
		has=false;
		repeat(i,0,n)
		repeat(j,0,m)
		if(f(i,j)){
			has=true;
			haslr[i]=hasud[j]=true;
		}
		else{
			ok=false;
			lr[i]=ud[j]=false;
		}
		if(ok){cout<<0<<endl;continue;}
		if(!has){cout<<"MORTAL"<<endl;continue;}
		bool ff=false;
		if(lr[0] || lr[n-1] || ud[0] || ud[m-1]){
			cout<<1<<endl;
			continue;
		}
		repeat(i,0,n)if(lr[i]){
			cout<<2<<endl;
			ff=true;break;
		}if(ff)continue;
		repeat(i,0,m)if(ud[i]){
			cout<<2<<endl;
			ff=true;break;
		}if(ff)continue;
		if(f(0,0) || f(0,m-1) || f(n-1,0) || f(n-1,m-1)){
			cout<<2<<endl;
			continue;
		}
		if(haslr[0] || haslr[n-1] || hasud[0] || hasud[m-1]){
			cout<<3<<endl;
			continue;
		}
		cout<<4<<endl;
	}
    return 0;
}