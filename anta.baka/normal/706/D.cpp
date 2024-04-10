#include <bits/stdc++.h>
using namespace std;

struct node {
	int z;
	node *t0, *t1;
	node() : z(0), t0(NULL), t1(NULL) {}
};

node root, *temp;

void add(int x) {
	bitset<32> foo = x;
	int cur = 31;
	node *v = &root;
	while(cur >= 0) {
		if(foo[cur] == 0) {
			if((*v).t0 == NULL)
				(*v).t0 = new node;
			(*(*v).t0).z++;
			v = (*v).t0;
		} else {
			if((*v).t1 == NULL)
				(*v).t1 = new node;
			(*(*v).t1).z++;
			v = (*v).t1;
		}
		cur--;
	}
}

inline void era(int x) {
	bitset<32> foo = x;
	int cur = 31;
	node *v = &root;
	while(cur >= 0) {
		if(foo[cur] == 0) {
			(*(*v).t0).z--;
			temp = &(*v);
			v = (*v).t0;
			if((*(*temp).t0).z == 0)
				(*temp).t0 = NULL;
		} else {
			(*(*v).t1).z--;
			temp = &(*v);
			v = (*v).t1;
			if((*(*temp).t1).z == 0)
				(*temp).t1 = NULL;
		}
		cur--;
	}
}

inline int query(int x) {
	bitset<32> foo = x, res = 0;
	int cur = 31;
	node *v = &root;
	while(cur >= 0) {
		if(foo[cur] == 1) {
			if((*v).t0 == NULL && (*v).t1 != NULL) {
				v = (*v).t1;
			} else if((*v).t0 != NULL) {
				res[cur] = 1;
				v = (*v).t0;
			}
		} else {
			if((*v).t1 == NULL && (*v).t0 != NULL) {
				v = (*v).t0;
			} else if((*v).t1 != NULL) {
				res[cur] = 1;
				v = (*v).t1;
			}
		}
		cur--;
	}
	return max((int)res.to_ulong(), x);
}

int main()
{
	ios_base::sync_with_stdio(0);
	int q;
	cin >> q;
	for(int i = 0, x; i < q; i++) {
		char t;
		cin >> t >> x;
		if(t == '+') {
			add(x);
		} else if(t == '-') {
			era(x);
		} else {
			cout << query(x) << "\n";
		}
	}
	return 0;
}