#include <bits/stdc++.h> 

using namespace std;

const int N = 200010;

struct data {
	int price, fro, bck, id;
	data () {}
	data (int a, int b, int c) {
		price = a, fro = b, bck = c;
	}
	bool operator < (const data &d) const {
		return price < d.price;
	}
};

int n, m;
data d[N];
int at[4], sz[4];
bitset <N> done;
vector <data> col[4];

int main (int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
  	scanf("%d", &d[i].price);
  	d[i].id = i;
  }
  for (int i = 1; i <= n; ++i) {
  	scanf("%d", &d[i].fro);
  }
  for (int i = 1; i <= n; ++i) {
  	scanf("%d", &d[i].bck);
  }
  sort(d + 1, d + n + 1);
  for (int i = 1; i <= n; ++i) {
  	int fr = d[i].fro, bc = d[i].bck;
  	col[fr].push_back(d[i]);
  	col[bc].push_back(d[i]);
  } 
  for (int i = 1; i <= 3; ++i) {
  	sz[i] = col[i].size();
  }
  scanf("%d", &m); while (m--) {
  	int c; scanf("%d", &c);
		while (at[c] < sz[c] and done[col[c][at[c]].id]) {
			++at[c];
		}
  	if (at[c] >= sz[c]) printf("-1 ");
  	else printf("%d ", col[c][at[c]].price), done[col[c][at[c]].id] = 1;
  }
  puts("");
  return 0;
}