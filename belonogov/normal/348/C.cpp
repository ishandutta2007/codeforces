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

const int maxn = 1e5 + 2;
const int maxSQ = 400;
const int inf = 1e9;

struct Query{
	char type;
	int k, x;
	Query(){}
	Query(char type, int k, int x): type(type), k(k), x(x) {}
};

int a[maxn];
vector < int > b[maxn]; /// input
long long res[maxn];
int c[maxSQ][maxn];
bool check[maxSQ][maxn];
long long upd[maxSQ];
int where[maxn];	
Query query[maxn];
vector < int > v;
vector < long long > answer;
vector < long long > answer2;

int n, m, q;


void read(){
	int k;
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 0; i < m; i++){
		scanf("%d", &k);
		b[i].resize(k);
		for (int j = 0; j < k; j++){
			scanf("%d", &b[i][j]); b[i][j]--;
		}
	}
	
	
	for (int i = 0; i < q; i++){
		scanf("\n%c%d", &query[i].type, &query[i].k); query[i].k--;
		assert(query[i].type == '+' || query[i].type == '?');
		if (query[i].type == '+')
			scanf("%d", &query[i].x);
	}
}

long long a2[maxn];
	
void solve(){
	char ch;
	int k, x;
	for (int i = 0; i < n; i++)
		a2[i] = a[i];
	v.clear();
	memset(upd, 0, sizeof(upd));
	memset(res, 0, sizeof(res));
	memset(c, 0, sizeof(c));
	
	for (int i = 0; i < m; i++){
		sort(b[i].begin(), b[i].end());
		int k = b[i].size();
		if (k * 1ll * k >= n){
			where[i] = v.size();
			v.pb(i);
			for (int j = 0; j < (int)b[i].size(); j++)
				res[where[i]] += a2[b[i][j]];
		}
	}
	memset(check, 0, sizeof(check));
	for (int i = 0; i < (int)v.size(); i++)
		for (int j = 0; j < (int)b[v[i]].size(); j++)
			check[i][b[v[i]][j]] = 1;
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < (int)v.size(); j++)
			for (int k = 0; k < (int)b[i].size(); k++)
				c[j][i] += check[j][b[i][k]];
				// 				c[i][j] += find(b[v[j]].begin(), b[v[j]].end(), b[i][k]) != b[v[j]].end();
	int cnt_big = v.size();
// 	cerr << "solve\n " << endl;
	for (int t = 0; t < q; t++){
		ch = query[t].type;
		k = query[t].k;
		x = query[t].x;
		if (ch == '+'){
// 			epr("x: %d\n", x);
			if ((int)b[k].size() * 1ll * (int)b[k].size() < n)
				for (int i = 0; i < (int)b[k].size(); i++)
					a2[b[k][i]] += x;
			else
				upd[where[k]] += x;
			
			for (int i = 0; i < (int)v.size(); i++)
				res[i] += x * 1ll * c[i][k];  	
		}
		if (ch == '?'){
			if ((int)b[k].size() * 1ll * (int)b[k].size() < n){
				long long sum = 0;
				for (int i = 0; i < (int)b[k].size(); i++)
					sum += a2[b[k][i]];
				for (int i = 0; i < cnt_big; i++)
					sum += upd[i] * c[i][k];
				answer.pb(sum);
			}
			else
				answer.pb(res[where[k]]);
		}
		
	}
}

void stupid(){
	int a2[maxn];
	char ch;
	int k, x;
	for (int i = 0; i < n; i++)
		a2[i] = a[i];
	for (int i = 0; i < q; i++){
		ch = query[i].type;
		k = query[i].k;
		x = query[i].x;
		if (ch == '+')
			for (int j = 0; j < (int)b[k].size(); j++)
				a2[b[k][j]] += x;
		if (ch == '?'){
			long long sum = 0;
			for (int j = 0; j < (int)b[k].size(); j++)
				sum += a2[b[k][j]];
			answer2.pb(sum);
		}
	}
	
}

void gen(){
	n = 10000, m = 10000, q = 10000;
	int n_sqrt = sqrt(n * 1.0), t0, t1, k;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10 - 5;
	for (int i = 0; i < m; i++){
		
		k = rand() % n_sqrt + 1;
		if (rand() % 2) 
			k = n / k;
		
		t0 = -1;
		b[i].resize(k);
		for (int j = 0; j < k; j++){
			t1 = t0 + rand() % 2 + 1;
			t1 = min(t1, n - (k - j - 1) - 1);
			b[i][j] = t1;
			assert(t0 < t1);
			t0 = t1;
		}		
	}
	for (int i = 0; i < q; i++)
		query[i] = Query("+?"[rand() % 2], rand() % n, rand() % 5);
// 	cerr << "success\n";	
}

void print(){
	printf("%d %d %d\n", n, m, q);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 0; i < m; i++){
		printf("%d ", (int)b[i].size());
		for (int j = 0; j < (int)b[i].size(); j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	for (int i = 0; i < q; i++)
		if (query[i].type == '+')
			printf("%c %d %d\n", query[i].type, query[i].k, query[i].x);
		else
			printf("%c %d\n", query[i].type, query[i].k);
	printf("smart: ");
	for (int i = 0; i < (int)answer.size(); i++)
		printf("%lld ", answer[i]);
	printf("\nstupid: ");
	for (int i = 0; i < (int)answer2.size(); i++)
		printf("%lld ", answer2[i]);
	printf("\n");			
}

void stress(){
	for (int t = 0; t < 10000; t++){
		cerr << "test id: " << t << endl;
		bool flag = 1;
		gen();
		answer.clear();
		answer2.clear();
		cerr << "smart\n";
		solve();
		cerr << "stupid\n";		
		stupid();
		assert(answer.size() == answer2.size());
		for (int i = 0; i < (int)answer.size(); i++)
			if (answer[i] != answer2[i])
				flag = 0;
	
		if (!flag){
			print();
			break;		
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
	solve();
	for (int i = 0; i < (int)answer.size(); i++)
		cout << answer[i] << "\n";
 
 
    return 0;
}