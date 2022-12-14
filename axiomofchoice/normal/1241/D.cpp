#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
const int N=300010;
int f[N],a[N],maxp[N],minp[N];
int p[N];
int top,n;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		repeat(i,0,n)f[i]=0;
		repeat(i,0,n){
			cin>>a[i];a[i]--;
			if(f[a[i]]==false)
				minp[a[i]]=maxp[a[i]]=i;
			else
				maxp[a[i]]=i;
			f[a[i]]=true;
		}
		top=0;
		repeat(i,0,n)
		if(f[i])
			p[top++]=i;
		int l=0,r=0,ans=0;
		repeat(i,0,top-1){
			if(maxp[p[i]]>minp[p[i+1]]){
				l=r=i+1;
			}
			else{
				r++;
				ans=max(ans,r-l);
			}
		}
		cout<<top-ans-1<<endl;
	}
	return 0;
}