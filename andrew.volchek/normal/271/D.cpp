#include <iostream>
#include <string>

using namespace std;

struct tnode
{
	tnode *nodes[26];

	tnode *go(char c)
	{
		c -= 'a';
		if(nodes[c] == NULL)
		{
			nodes[c] = new tnode();
		}
		return nodes[c];
	}

	tnode()
	{
		for(int i=0;i<26;i++)
			nodes[i] = NULL;
	}
};

long ans = 0;

void dfs(tnode *p)
{
	for(int i=0;i<26;i++)
	{
		if(p->nodes[i])
		{
			ans++;
			dfs(p->nodes[i]);
		}
	}
}


int main()
{
	string str;

	cin >> str;

	bool good[26];
	for(int i=0;i<26;i++)
	{
		char c;
		cin >> c;
		good[i] = c == '1';
	}

	int k;
	cin >> k;

	tnode *root = new tnode();

	for(int i=0;i<str.length();i++)
	{
		int bk = 0;
		tnode *p = root;
		for(int j=i;j<str.length();j++)
		{
			bk += !good[str[j]-'a'];

			if(bk > k)
				break;

			p = p->go(str[j]);
		}
	}

	dfs(root);

	cout << ans;


	return 0;
}