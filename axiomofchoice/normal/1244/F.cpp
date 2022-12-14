#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define int ll
int a[200010],t1[200010],t2[200010];
int n,k;
string s;
void get_t1(int x){
	if(t1[x]!=-1)return;
	if(a[x]){t1[x]=0;return;}
	get_t1((x+n-1)%n);
	t1[x]=t1[(x+n-1)%n]+1;
}
void get_t2(int x){
	if(t2[x]!=-1)return;
	if(a[x]){t2[x]=0;return;}
	get_t2((x+1)%n);
	t2[x]=t2[(x+1)%n]+1;
}
char change(char c,int n){if(n%2==1)c='W'+'B'-c;return c;}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;
	cin>>s;
	mst(a,0); mst(t1,-1); mst(t2,-1);
	bool f=false;
	repeat(i,0,n){
		if(s[i]==s[(i+1)%n]){
			a[i]=a[(i+1)%n]=1;
			f=true;
		}
	}
	if(f){
		repeat(i,0,n){
			get_t1(i);
			get_t2(i);
			int t=min(t1[i],t2[i]);
			if(t<=k)cout<<change(s[i],t);
			else cout<<change(s[i],k);
		}
	}
	else repeat(i,0,n)cout<<change(s[i],k);
	cout<<endl;
	return 0;
}