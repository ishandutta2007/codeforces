#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N (1048576*2+10)
#define mod 1000000007
//#define int ll
char ch[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int T,n,m,k;
char s[110][110];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		repeat(i,0,n)cin>>s[i];
		int sum=0;
		repeat(i,0,n)
		repeat(j,0,m){
			if(s[i][j]=='R')
				sum++;
		}
		int b=sum-k*(sum/k),a=k-sum+k*(sum/k);
		int top=0;
		int cnt=0;
		repeat(i,0,n)
		repeat(j,0,m){
			//cout<<a<<" "<<b<<endl;
			int kk=j,maxcnt=top<b?(sum/k+1):(sum/k);
			if(i%2==0)kk=m-j-1;//cout<<k<<endl;
			if(s[i][kk]=='R')
				cnt++;
			s[i][kk]=ch[top];//cout<<top<<endl;
			if(cnt==maxcnt){
				top++;
				top=min(top,k-1);
				cnt=0;
			}
		}
		repeat(i,0,n)cout<<s[i]<<endl;
	}
	return 0;
}