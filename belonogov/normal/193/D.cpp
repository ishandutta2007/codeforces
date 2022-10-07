#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 3e5 + 2;
const int max_sqr = 600;
const int inf = 1e9;

int a[maxn];
int b[maxn];
int c[maxn];
int q[max_sqr][max_sqr];
int uk[max_sqr];
int n, block_sz, cnt_block;
int MOD;

void re_build_block_1(int i){
	int st = i * block_sz;
	for (int j = 0; j < block_sz; j++)
		c[st + j] += uk[i];
	uk[i] = 0;
}

void re_build_block_2(int i){
	memset(q[i], 0, sizeof(q[i]));
	int l = i * block_sz;
	for (int j = 0; j < block_sz; j++)
		if (c[l + j] <= block_sz + 2)
			q[i][c[l + j]]++;
}

void re_build(){
	for (int i = 0; i < cnt_block; i++){
		re_build_block_1(i);
		re_build_block_2(i);		
	}
}

void add(int l, int r, int val){
	int i;
	r++;
	while (l < r){
		if ((l & MOD) == 0 && l + block_sz <= r){
			i = l >> 9;
			uk[i] += val;
			if (abs(uk[i]) > block_sz - 2){
				re_build_block_1(i);
				re_build_block_2(i);					
			}
			l += block_sz;
			continue;
		}
		
		i = l >> 9;
		
		re_build_block_1(i);
		for (int j = l; j < min(r, (i + 1) << 9); j++)
			c[j] += val;
		re_build_block_2(i);
		
		l = min(r, (i + 1) << 9);
	}
}

int get(int l, int r){
	int ans = 0, i;
	r++;
	while (l < r){
		if ((l & MOD) == 0 && l + block_sz <= r){
			int i = l >> 9;
			if (1 - uk[i] > 0)
				ans += q[i][1 - uk[i]];
			if (2 - uk[i] > 0)
				ans += q[i][2 - uk[i]];
			l += block_sz;
			continue;			
		}
		i = l >> 9;

		re_build_block_1(i);
		for (int j = l; j < r && j < (i + 1) << 9; j++)
			ans += (c[j] == 1 || c[j] == 2);
	
		re_build_block_2(i);
		l = min(r, (i + 1) << 9);
	}
	return ans;
}

void read(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i]--;		
	}	
}

long long solve(){
	long long ans = 0;
	int res, d;
	vector < int > x;
	for (int i = 0; i < n; i++)
		b[a[i]] = i;
	
	res = 0;
	for (int i = 0; i < n; i++){
		d = 0;
		if (b[i] != 0 && a[b[i] - 1] < i)
			d++;
		if (b[i] != n - 1 && a[b[i] + 1] < i)
			d++;
		res -= (d - 1);
		c[i] = res;		
	}
	
// 	block_sz = sqrt(n);
	block_sz = 512;
	MOD = block_sz - 1;
	cnt_block = (n + block_sz - 1) / block_sz;
	
	re_build();

	for (int i = 0; i < n; i++){
// 		if (i % block_sz == 0)
		ans += get(i, n - 1);
		x.clear();
		if (b[i] != 0 && a[b[i] - 1] > i)
			x.pb(a[b[i] - 1]);
		if (b[i] != n - 1 && a[b[i] + 1] > i)
			x.pb(a[b[i] + 1]);
		sort(x.begin(), x.end());
		if ((int)x.size() == 2){
			add(i + 1, x[0] - 1, -1);
			add(x[1], n - 1, 1);
		}
		if ((int)x.size() == 1)
			add(i + 1, x[0] - 1, -1);
		if ((int)x.size() == 0)
			add(i + 1, n - 1, -1);
	}
	
	return ans - n;	
}

void gen_test(){
	n = 5000;
	for (int i = 0; i < n; i++)
		a[i] = i;
	random_shuffle(a, a + n);
}

long long stupid(){
	long long ans = 0;
	int cnt, d;
	for (int i = 0; i < n; i++)
		b[a[i]] = i;
	for (int i = 0; i < n; i++){
		cnt = 0;
		for (int j = i; j < n; j++){
			d = 1;
			if (b[j] != 0 && i <= a[b[j] - 1] &&  a[b[j] - 1] < j) 
				d--;
			if (b[j] != n - 1 && i <= a[b[j] + 1] && a[b[j] + 1] < j)
				d--;
			cnt += d;
			ans += (cnt == 1 || cnt == 2);			
		}
			
	}
	return ans - n;	
}


void stress(){
	int t = 100;
	long long ans1, ans2;
	while (t --> 0){
		epr("test id: %d\n", t);
		gen_test();
		ans1 = solve();
// 		cerr << "end\n";
		ans2 = stupid();

		if (ans1 != ans2){
			for (int i = 0; i < n; i++)
				cerr << a[i] + 1 << " ";
			cerr << "\nans1   ans2   " << ans1 << " " << ans2 << endl;
			exit(0);
		}
			
	}
	exit(0);
	
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	
	if (0)
		stress();
	
	read();
	cout << solve() << endl;
	

    return 0;
}