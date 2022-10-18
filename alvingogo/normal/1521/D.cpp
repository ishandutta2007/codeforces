#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct no{
	vector<int> ch;
};
vector<no> v;
vector<pair<int,int> > del,li;
int dfs(int r,int f){
	int flag=0;
	int lf=-1,an=-1;
	for(auto h:v[r].ch){
		if(h!=f){
			int c=dfs(h,r);
			if(c==-2){
				continue;
			}
			if(lf==-1){
				lf=c;
			}
			else{
				if(flag==0){
					if(r!=f){
						del.push_back({r,f});
					}
					flag=1;
					an=c;
				}
				else{
					del.push_back({h,r});
					li.push_back({h,c});
				}
			}
		}
	}
	if(an!=-1){
		li.push_back({lf,an});
		return -2;
	}
	if(lf==-1){
		lf=r;
	}
	if(r==0){
		li.push_back({lf,r});
	}
	return lf;
}
int main(){
    AquA;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		v.clear();
		v.resize(n);
		for(int i=1;i<n;i++){
			int a,b;
			cin >> a >> b;
			a--;
			b--;
			v[a].ch.push_back(b);
			v[b].ch.push_back(a);
		}
		del.clear();
		li.clear();
		dfs(0,0);
		cout << del.size() << "\n";
		assert(del.size()+1==li.size());
		for(int i=0;i<del.size();i++){
			cout << del[i].fs+1 << " " << del[i].sc+1 << " " << li[i].fs+1 << " " << li[i+1].sc+1 << "\n";
		}
	}
	return 0;
}