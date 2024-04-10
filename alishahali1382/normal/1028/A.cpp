#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=120;

ll n, m, x, y;
//string s[MAXN];
char ch;
vector <pair<int, int>> vec;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin>>ch;
			if (ch=='B') vec.push_back({i, j});
		}
	}
	if (vec.size()==1){
		cout<<vec[0].first+1<<' '<<vec[0].second+1<<endl;
		return 0;
	}
	int k=vec.size()-1;
	x=(vec[0].first+vec[k].first)/2;
	y=(vec[0].second+vec[k].second)/2;
	cout<<x+1<<' '<<y+1<<endl;
	
	
		
	
	return 0;
}