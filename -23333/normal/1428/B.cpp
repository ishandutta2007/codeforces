#include<bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int  N=3e5+222;
int cnt,b[N];
int a[N];
int n,t,s1,s2;
int main(){
	//freopen("p.in","r",stdin);
	//freopen("p.out","w",stdout);
//	std::pair<int,int> re;
	cin>>t;
	rep(numx,1,t){
		
		cin>>n;
		s1=s2=0;
		rep(i,1,n){
			char c;
			cin>>c;
			if(c=='>'){a[i]=-1;s1++;}
			if(c=='<'){a[i]=1;s2++;}
			if(c=='-'){a[i]=0;s1++;s2++;}
		}
		
		if(s1==n||s2==n){cout<<n<<endl;continue;}

		int ans=0;

		if(a[1]==0||a[n]==0)ans++;
		for(int i=2;i<=n;i++)if(a[i]==0||a[i-1]==0)ans++;
		cout<<ans<<endl;
	}
	return 0;
}