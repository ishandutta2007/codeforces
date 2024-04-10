#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 1000010
#define int ll
int t,n;
vector<int> a[200010],s;
priority_queue<int> q;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		repeat(i,0,n){
			int m,p;
			cin>>m>>p;
			a[m].push_back(p);
		}
		q=priority_queue<int>();
		int cnt=0;
		repeat(i,0,n){
			while(!a[i].empty())
				q.push(a[i].back()),a[i].pop_back();
			if(q.empty())cnt++;
			else
				q.pop();
		}
		s.clear();
		while(!q.empty())s.push_back(q.top()),q.pop();
		int ans=0;
		repeat_back(i,0,s.size()){
			if(cnt<=0)break;
			ans+=s[i];
			cnt--;
		}
		cout<<ans<<endl;
	}
	return 0;
}