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
#define int ll
int T;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b; if(a>b)swap(a,b); //a<b
		int n=b-a,sum=0;
		if(n==0){cout<<0<<endl; continue;}
		repeat(i,1,1e9){
			sum+=i;
			if(n==sum){cout<<i<<endl; break;}
			if(sum>n){
				if((sum-n)%2==0){
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}