#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#define ll long long
#define N 305
using namespace std;
int n,m,cnt,used[N],ans,mid,sum[N];
string s[N],temp;
bool vis[N];
map<string,int> M;
vector<int> v;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n >> m;	
	for(int i = 1;i <= n;++i){
		cin >>	s[i];
		temp = s[i];
		reverse(temp.begin(),temp.end());
		if(M.count(s[i])>0){
			used[i] = 1;
		}
		else{
			M[s[i]] = ++cnt;
			M[temp] = cnt;
		}
		sum[M[s[i]]]++;
	}
	for(int i = 1;i <= n;++i){
		if(used[i]==0) continue;
		int t = sum[M[s[i]]]/2;
		if(vis[M[s[i]]]) continue;
		vis[M[s[i]]] = 1;
		for(int j = 1;j <= t;++j){
			ans++;
			v.push_back(i);
		}
	}
	for(int i = 1;i <= n;++i){
		temp = s[i];
		reverse(temp.begin(),temp.end());
		if(temp != s[i]) continue;
		if(sum[M[s[i]]]%2==1) mid = i;
	
	}
	ans *= 2*m;
	if(mid) ans += m;
	cout << ans << endl;
	for(int i = 0;i < v.size();++i) cout << s[v[i]];
	if(mid) cout << s[mid];
	for(int i = int(v.size())-1;i >= 0;--i){
		temp = s[v[i]];
		reverse(temp.begin(),temp.end());
		cout << temp;
	}
    return 0;
}