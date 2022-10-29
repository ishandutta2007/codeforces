//http://codeforces.com/contest/557/problem/E
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

vector<pair<int,int> > v;

char s[5123];
bool been[5123][5123];
bool tab[5123][5123];
int n;

class Node
{
public:
	Node() : x(0), val(0){
		next[0] = next[1] = NULL;
	}
	~Node(){
		for(int i = 0; i < 2; i++)
			if(next[i] != NULL)
				delete next[i];
	}
	
	Node *next[2];
	int x, val;

	void garante(int i)
	{
		if(next[i] == NULL)
			next[i] = new Node;
	}

	int dfs()
	{
		val = x;
		for(int i = 0; i < 2; i++)
			if(next[i] != NULL)
				val += next[i]->dfs();
		return val;
	}

	void ans(int k)
	{
		k -= x;
		if(k <= 0)
			return;
		garante(0), garante(1);
		if(next[0]->val >= k)
		{
			printf("a");
			next[0]->ans(k);
		}
		else
		{
			printf("b");
			next[1]->ans(k - next[0]->val);
		}
	}

};

int pd(int i, int j)
{
	if(j <= i)
		return true;
	if(been[i][j])
		return tab[i][j];
	been[i][j] = true;
	return tab[i][j] = ((s[i] == s[j]) && pd(i+2, j-2));
}

int main(int argc, char const *argv[])
{
	int k;
	scanf("%s %d", s, &k);
	n = strlen(s);

	Node *root = new Node;
	for(int i = 0; i < n; i++)
	{
		Node *cur = root;
		for(int j = i; j < n; j++)
		{
			cur->garante(s[j] - 'a');
			cur = cur->next[s[j] - 'a'];
			if(pd(i,j))
				cur->x++;
		}
	}
	root->dfs();
	root->ans(k);

	printf("\n");
	return 0;
}