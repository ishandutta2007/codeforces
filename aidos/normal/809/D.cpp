#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

struct node{
	int y, cnt, val;
	node * l, *r;
	int ad;
	node(){
		cnt = 0;
		val = 0;
		ad = 0;
	}
	node(int _y, int _val, node * _l, node *_r){
		y = _y;
		val = _val;
		l = _l;
		r = _r;
		cnt = 1;
		ad = 0;
	}
};
inline int getCnt(node *T){
	if(T == NULL) return 0;
	return T->cnt;
}


inline void update(node * &T){
	T->cnt = getCnt(T->l) + getCnt(T->r) + 1;
}
inline void push(node * &T){
	if(T == NULL)
		return;
	T->val += T->ad;
	if(T->ad > 0){
		if(T->l) T->l->ad += T->ad;
		if(T->r) T->r->ad += T->ad;
		T->ad = 0;
	}
}

inline  void split1(node *T,node* &l, node *&r, int x){
	if(T == NULL){
		l = NULL;
		r = NULL;
		return ;
	}
	push(T);

	if(T->val >= x){
		split1(T->l, l, T->l, x);
		r = T;
		update(r);
	}
	else{
		split1(T->r, T->r, r, x);
		l = T;
		update(l);
	}
}
inline  void split2(node *T,node* &l, node *&r, int y){
	if(T == NULL){
		l = NULL;
		r = NULL;
		return ;
	}
	push(T);

	if(T->val >= y){
		split2(T->l, l, T->l, y);
		r = T;
		update(r);
	}
	else{
		split2(T->r, T->r, r, y);
		l = T;
		update(l);
	}
}
inline  void split(node *T,node* &l, node *&r, int cur){
	if(T == NULL){
		l = NULL;
		r = NULL;
		return ;
	}
	push(T);
	if(getCnt(T->l) >= cur){
		split(T->l, l, T->l, cur);
		r = T;
		update(r);
	}
	else{
		split(T->r, T->r, r, cur - getCnt(T->l) - 1);
		l = T;
		update(l);
	}
}


inline  void merge(node * &T, node * l, node * r){
	push(l);
	push(r);
	if(l == NULL) T = r;
	else if(r==NULL) T = l;
	else{
		if(l->y>r->y){                           
			merge(l->r, l->r, r);
			T = l;
			update(T);
		}
		else{
			merge(r->l, l, r->l);
			T = r;
			update(T);
		}
	}
}





inline  void show(node * T, int &ind){
	if(T == NULL) return;
	show(T->l, ind);
	cout << T->val << " " << ind << endl;	
	ind++;
	show(T->r, ind);
	update(T);
}


void traverse(node * root){
	if(root == NULL) return;
	push(root);
	traverse(root->l);
	cout << root->val<<" ";
	traverse(root->r);
}   

inline void solve(){
	int n;
	scanf("%d", &n);
	node * root = NULL, *l1, *l2, *l3, *l4, *l5, *l6, *l7;
	node * cur = new node((rand()<<13) | rand(), 0, NULL, NULL);
	merge(root, root, cur);
	
	for(int i = 0, l, r; i < n; i++){
		scanf("%d%d", &l, &r);
		push(root);
		split2(root, l1, l2, l);
		push(l1);
		push(l2);
		split1(l2, l3, l4, r);
		if(getCnt(l3) > 0){
			split(l3, l5, l6, 1);
			push(l5);
			node * cur;
			if(getCnt(l1) > 0) cur = new node((rand()<<13) | rand(), l, NULL, NULL);
			else cur = new node((rand()<<13) | rand(), l5->val, NULL, NULL);
			push(l6);
			merge(l3, l5, l6);
			l3->ad++;
			push(l3);
			merge(l3, cur, l3);
		}
		else {
			//node * cur;
			if(getCnt(l1) > 0) l3 = new node((rand()<<13) | rand(), l, NULL, NULL);
			//else cur = new node((rand()<<13) | rand(), l5->val, NULL, NULL);
		}
		if(getCnt(l4) == 0){

			push(l1);
			push(l3);
			push(l4);
			merge(root, l1, l3);
			merge(root, root, l4);
		}
		else {
			push(l4);
			split(l4, l5, l6, 1);
			push(l1);
			push(l3);
			merge(root, l1, l3);
			push(l6);
			merge(root, root, l6);
		}
		//traverse(root);
		//cout << endl;
	}
	//traverse(root);
	//cout << endl;
	cout << getCnt(root) - 1<<endl;

}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
	srand(123123);
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}