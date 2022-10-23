# include <map>
# include <deque>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int n, k, m;
deque <int> q;
map <int, bool> mp;
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		int id;
		scanf("%d", &id);
		if (mp.find(id) == mp.end() || !mp[id]){
			mp[id] = true;
			q.push_back(id);
			if (m == k){
				mp[q.front()] = false;
				q.pop_front();
			} else ++m;
		}
	}
	printf("%d\n", m);
	while (!q.empty()){
		printf("%d ", q.back());
		q.pop_back();
	}
	return 0;
}