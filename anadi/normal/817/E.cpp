#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second

struct node{
	int pod = 0;
	node* left = nullptr;
	node* right = nullptr;
	node(int _pod = 0, node* _left = nullptr, node* _right = nullptr) : pod(_pod), left(_left), right(_right) { }
};

node* root = new node;

inline node* lewy(node* now){
	if(now->left == nullptr)
		now->left = new node;
	return now->left;
}

inline node* prawy(node* now){
	if(now->right == nullptr)
		now->right = new node;
	return now->right;
}

inline void add(int val){
	int p;
	scanf("%d", &p);
	node* now = root;
	for(int i = 26; i >= 0; --i){
		if(p & (1 << i))
			now = prawy(now);
		else
			now = lewy(now);
		now->pod = (now->pod) + val;
	}
}

inline int pod(node* wsk){
	if(wsk == nullptr)
		return 0;
	return wsk->pod;
}

inline void ask(){
	int p, l;
	scanf("%d %d", &p, &l);
	node* now = root;
	
	int res = 0;
	for(int i = 26; i >= 0; --i){
		if(now == nullptr)
			break;

		if(l & (1 << i)){
			if(p & (1 << i))
				res += pod(now->right),
				now = now->left;
			else
				res += pod(now->left),
				now = now->right;			
		}
		else{
			if(p & (1 << i))
				now = now->right;
			else
				now = now->left;
		}
	}
	
	printf("%d\n", res);
}

inline void solve(){
	int type;
	scanf("%d", &type);
	if(type == 1)
		add(1);
	else if(type == 2)
		add(-1);
	else
		ask();
}

int main(){
	int quest;
	scanf("%d", &quest);
	while(quest--)
		solve();
	return 0;
}