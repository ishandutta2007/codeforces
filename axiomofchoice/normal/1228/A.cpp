#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a,b;
	cin>>a>>b;
	char c[10];
	string s;
	int f[10];
	int ans=-1,flag;;
	repeat(x,a,b+1){
		sprintf(c,"%d",x);
		s=c;
		mst(f,0);
		flag=true;
		repeat(i,0,s.length()){
			if(f[s[i]-'0']){
				flag=false;
				break;
			}
			f[s[i]-'0']=1;
		}
		if(flag){
			ans=x;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}