#include <cstdio>
#include <set>
#include <cstring>

const int MAX_LEVEL = 20;

struct Tree
{
	int count;
	Tree* child[2];

	Tree() : count(0) {
		for (int i = 0; i < 2; i++)
			child[i] = nullptr;
	}
	Tree(int cnt) : count(cnt) {
		for (int i = 0; i < 2; i++)
			child[i] = nullptr;
	}

	void Add(char* num, int size)
	{
		if (size == MAX_LEVEL)
			count++;
		else
		{
			int len = strlen(num);
			int ind;
			if (len <= size)
				ind = 0;
			else
				ind = (num[len - size - 1] - '0') % 2;

			if (child[ind] == nullptr)
				child[ind] = new Tree();
			child[ind]->Add(num, size + 1);
		}
	}

	void Sub(char* num, int size)
	{
		if (size == MAX_LEVEL)
			count--;
		else
		{
			int len = strlen(num);
			int ind;
			if (len <= size)
				ind = 0;
			else
				ind = (num[len - size - 1] - '0') % 2;
			
			child[ind]->Sub(num, size + 1);
		}
	}

	int CountNum(char* str, int size)
	{
		if (size == MAX_LEVEL)
			return count;
		else
		{
			int len = strlen(str);
			int ind;
			if (len < size)
				ind = 0;
			else
				ind = (str[len - size - 1] - '0') % 2;

			if (child[ind] == nullptr)
				return 0;

			return child[ind]->CountNum(str, size + 1);
		}
	}
};

Tree* root;

char str[30];

int main()
{
	root = new Tree();
	root->child[0] = new Tree();
	root->child[1] = new Tree();

	int test = 0;
	scanf("%d", &test);
	while (test--)
	{
		char ch;
		long long num = 0;
		scanf(" %c %s", &ch, str);
		if (ch == '+')
		{
			root->Add(str, 0);
		}
		else if (ch == '-')
		{
			root->Sub(str, 0);
		}
		else
		{
			printf("%d\n", root->CountNum(str, 0));
		}
	}

	return 0;
}