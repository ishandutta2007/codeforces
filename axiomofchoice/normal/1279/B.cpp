#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=100010;
const int inf=1e9;
const int mod=1000000007;
#define int ll
int t,a[N],n,s;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>s;
		repeat(i,0,n){
			cin>>a[i];
		}
		int m=0;
		repeat(i,0,n){
			if(a[m]<a[i])m=i;
			s-=a[i];
			if(s<0 && s+a[m]>=0){
				break;
			}
			if(s<0 || i==n-1){
				m=-1;
				break;
			}
		}
		cout<<m+1<<endl;
	}
	return 0;
}