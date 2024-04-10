#include <bits/stdc++.h>
using namespace std;

set <pair<int, int> > points;
string str, khela[10010];


int main(int argc, char const *argv[]) {
	//freopen ("in.txt", "r", stdin);

	int n; scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		int x; scanf("%d",&x);
		str += '0';
		points.insert(make_pair (x, i));
	}

	int now = 0;
	while(true) {
		auto iterator = points.end(); iterator --;
		auto i = iterator;
		auto j = iterator;
		pair <int, int>  x = * (i);
		if(points.begin() -> first == x.first) break;
		i--; pair <int, int> y= *(i);

		int cur_max = x.first;
		
		if(y.first != x.first) {
			khela[now] = str;
			khela[now][x.second] = '1';
			khela[now][y.second] = '1';
			points.erase(i); points.erase(j);
			x.first = max(x.first - 1, 0);
			y.first = max(y.first - 1, 0);
			points.insert(x); points.insert(y);
		}
		else {
			i = j;
			khela[now] = str;
			stack <pair <int, int> > used;
			int count = 0;
			while(i -> first == cur_max && count < 6) {
				khela[now][i->second]='1';
				used.push(*i);
				i--; count++;
			}
			if(count == 6) {
				while(count > 4) {
					int number = used.top().second;
					khela[now][number]='0';
					count--; used.pop(); i++;
				}
			}
			i++;
			points.erase(i, points.end());
			while(not used.empty()) {
				pair <int, int>  xx = used.top();
				xx.first = max(xx.first-1,0);
				points.insert(xx); used.pop();
			}
		}
		now ++;
	}
	printf("%d\n%d\n", points.begin()->first, now);
	
	for(int i = 0; i < now; i++)
		printf("%s\n", khela[i].c_str());

	return 0;
}