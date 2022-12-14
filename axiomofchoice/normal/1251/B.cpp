#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 1000010
int n,tot[2],pr,sg,t;
vector<int> a;
string s;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		a.clear();
		mst(tot,0);
		repeat(i,0,n){
			cin>>s;
			repeat(j,0,s.size())
				tot[s[j]-'0']++;
			a.push_back(s.size());
		}
		pr=tot[0]/2+tot[1]/2;pr*=2;
		sg=tot[0]%2+tot[1]%2;
		sort(a.begin(),a.end());
		int ans=0;
		repeat(i,0,a.size()){
			pr-=a[i]-a[i]%2;
			a[i]=a[i]%2;
			if(sg<a[i]){pr--; sg+=2;}
			sg-=a[i];
			if(pr<0)break;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}