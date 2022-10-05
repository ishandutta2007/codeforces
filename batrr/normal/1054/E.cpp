#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void CIN(string &s){
	char ch = getchar();
	while(ch != '0' && ch != '1')
		ch = getchar();
	while(ch == '0' || ch == '1'){
		s += ch; 
		ch = getchar();
	}
}
const int N = (int)305, inf = 1e9;
const ll INF = 1e18;

int n, m, sum, cnt1[N][N], cnt2[N][N];
string a[N][N], b[N][N];
vector< pair< pii, pii > > ans1, ans2;
// (1, 1) - 0
// (n, m) - 1
void solve1(){                    
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
			for(int q = a[i][j].size() - 1 ; q >= 0; q--){
				if(a[i][j][q] == '0'){ 
					if(j == 0){
						if(i == 0){
							cnt1[1][0]++;
							ans1.pb({{i, 0}, {1, 0}});
			    		}else{
			    			cnt1[0][0]++;
			    			ans1.pb({{i, j}, {0, 0}});
			    		}
					}else{
                    	cnt1[i][0]++;
                    	ans1.pb({{i, j}, {i, 0}});
			    	}
				}else{
					if(j == 1){
						if(i == 0){
							cnt1[1][1]++;
							ans1.pb({{i, 1}, {1, 1}});
			    		}else{
			    			cnt1[0][1]++;
			    			ans1.pb({{i, j}, {0, 1}});
			    		}
					}else{
                    	cnt1[i][1]++;
                    	ans1.pb({{i, j}, {i, 1}});
			    	}
				}
			}
		}
	}
	for(int i = 1; i < n; i++){
		while(cnt1[i][0]--)
			ans1.pb({{i, 0},{0, 0}});
		while(cnt1[i][1]--)
			ans1.pb({{i, 1},{0, 1}});
	}
}
void solve2(){                    
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
			for(int q = 0; q < b[i][j].size(); q++){
				if(b[i][j][q] == '0'){ 
					if(j == 0){
						if(i == 0){
							cnt2[1][0]++;
							ans2.pb({{i, 0}, {1, 0}});
			    		}else{
			    			cnt2[0][0]++;
			    			ans2.pb({{i, j}, {0, 0}});
			    		}
					}else{
                    	cnt2[i][0]++;
                    	ans2.pb({{i, j}, {i, 0}});
			    	}
				}else{
					if(j == 1){
						if(i == 0){
							cnt2[1][1]++;
							ans2.pb({{i, 1}, {1, 1}});
			    		}else{
			    			cnt2[0][1]++;
			    			ans2.pb({{i, j}, {0, 1}});
			    		}
					}else{
                    	cnt2[i][1]++;
                    	ans2.pb({{i, j}, {i, 1}});
			    	}
				}
			}
		}
	}
	for(int i = 1; i < n; i++){
		while(cnt2[i][0]--)
			ans2.pb({{i, 0},{0, 0}});
		while(cnt2[i][1]--)
			ans2.pb({{i, 1},{0, 1}});
	}
}
int get(pii x, pii y){      
	a[y.f][y.s] = a[x.f][x.s].substr(a[x.f][x.s].size() - 1, 1) + a[y.f][y.s];
	a[x.f][x.s] = a[x.f][x.s].substr(0, a[x.f][x.s].size()- 1);
    for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << a[i][j]<< " ";
		cout << endl;
	}
	cout << endl;
	//exit(0);
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
				CIN(a[i][j]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) 
				CIN(b[i][j]);
	solve1();
	solve2();
	for(int i = 0; i < ans2.size(); i++)
		swap(ans2[i].f, ans2[i].s);
	reverse(ans2.begin(),ans2.end());
	
	/*
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
				cin >> a[i][j];
	//return 0;
	for(auto it : ans1)
		get(it.f, it.s);
	for(auto it : ans2)
		get(it.f, it.s);
	return 0;
	*/
	//cerr << sum * 4 << endl;
	printf("%d\n", ans1.size() + ans2.size());                
	for(auto it : ans1)
		printf("%d %d %d %d\n", it.f.f + 1, it.f.s + 1, it.s.f + 1, it.s.s + 1);
	for(auto it : ans2)
		printf("%d %d %d %d\n", it.f.f + 1, it.f.s + 1, it.s.f + 1, it.s.s + 1);
	return 0;
}