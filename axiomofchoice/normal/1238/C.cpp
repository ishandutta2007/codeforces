#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
deque<int> q;
ll h,n,x;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		cin>>h>>n;
		int ans=0;
		q.clear();
		repeat(i,0,n){
			cin>>x;
			q.push_back(x);
		}
		while(1){
			if(q.size()<=1)break;
			if(q.size()==2){
				if(q[1]!=1)ans++;
				break;
			}
			q[0]=q[1]+1;
			if(q[0]==q[1]+1 && q[0]!=q[2]+2){
				int t=q[0];
				q.pop_front();
				q.pop_front();
				q.push_front(t-2);
				ans++;
				continue;
			}
			if(q[0]==q[1]+1 && q[0]==q[2]+2){
				q.pop_front();
				q.pop_front();
				continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}