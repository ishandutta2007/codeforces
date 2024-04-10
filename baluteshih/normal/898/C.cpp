#include <iostream>
#include <map>
using namespace std;

struct node
{
	int size=0;
	node *child[10]={0};
	void up()
	{
		size=0;
		for(int i=0;i<10;i++)
			if(child[i]) size+=child[i]->size;
	}
};

map<string,node*> trie;

void push(node *p,string s)
{
	if(s=="") 
	{
		int i;
		for(i=0;i<10;i++)
			if(p->child[i]) break;
		if(i==10) p->size=1;
		return;
	} 
	if(p->child[s.back()-'0']==0) p->child[s.back()-'0']=new node;
	node *tmp=p->child[s.back()-'0'];
	s.pop_back();
	push(tmp,s);
	p->up();
}

void dfs(node *p,string s)
{
	int flag=0;
	for(int i=0;i<10;i++)
		if(p->child[i]) dfs(p->child[i],(char)('0'+i)+s),flag=1;
	if(!flag) cout << " " << s; 
}

int main()
{
	int n,i;
	string s,x;
	node *tmp;
	cin >> n;
	while(n--)
	{
		cin >> s;
		if(trie[s]==0) trie[s]=new node;
		tmp=trie[s],cin >> i;
		while(i--)
			cin >> x,push(tmp,x);
	}
	cout << trie.size() << "\n";
	for(auto p=trie.begin();p!=trie.end();p++)
		cout << p->first << " " << p->second->size,dfs(p->second,""),cout << "\n";
}