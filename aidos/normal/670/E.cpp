#include<iostream>
#include<cstdio>

using namespace std;
#define prev asdfadf
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

int n, m, p;

char d[500100];

struct node{
	node * left;
	node * right;
	char c;
	node(){
		left = NULL;
		right = NULL;
		c = 0;
	}

	void print(){
		putchar(c);
	}
};
node * link[500500];

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	scanf("%d %d %d", &n, &m, &p);
	scanf("%s", d + 1);

	for (int i = 0; i <= n + 1; i++){
		link[i] = new node();
	}
	for (int i = 0; i <= n + 1; i++){
		if (i <= n) link[i]->right = link[i + 1];
		if (i > 0) link[i]->left = link[i - 1];
		link[i]->c = d[i];
	}
	scanf("%s", d);
	node * pos = link[p];


	for (int i = 0; i < m; i++){
		if (d[i] == 'L') {
			pos = pos->left;
		}
		else if (d[i] == 'R'){
			pos = pos->right;
		}
		else {
			node * cur = pos;
			int val;
			if (pos->c == '(') {
				val = -1;
				pos = pos->right;
			}
			else {
				val = 1;
				pos = pos->left;
			}
			while (val != 0){
				if (pos->c == '(')
					val--;
				else
					val++;
				if (val < 0) pos = pos->right;
				else if (val > 0) pos = pos->left;
			}
			if (cur->c == ')'){
				pos->left->right = cur->right;
				cur->right->left = pos->left;
				pos = cur->right;
				if (pos->right == NULL) pos = pos->left;
			}
			else {
				cur->left->right = pos->right;
				pos->right->left = cur->left;
				pos = pos->right;
				if (pos->right == NULL) pos = pos->left;
			}
		}
	}
	pos = link[0]->right;
	while (pos->right != NULL){
		pos->print();
		pos = pos->right;
	}





#ifdef LOCAL
	cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}