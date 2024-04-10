#include<cstdio>
#include<algorithm>
using namespace std;

struct node
{
	node *left, *right;
	double val, ow;
	node(int x = 0)
	{
		val = x;
		ow = 0;
		left = right = NULL;
	}
};

int n,h,Q;
char ex[22];

double go(node *v, double alt)
{
	if(v->left == NULL && v->right == NULL)
		return max(alt, v->ow);
	if(v->left == NULL)
	{
		if(alt > v->right->val+v->ow) return alt;
		return .5 * (v->right->val+v->ow + go(v->right, max(alt, v->ow)));
	}
	if(v->right == NULL)
	{
		if(alt > v->left->val+v->ow) return alt;
		return .5 * (v->left->val+v->ow + go(v->left, max(alt, v->ow)));
	}
	double left = v->left->val, right = v->right->val;
	if(alt >= left+v->ow && alt >= right+v->ow) return alt;
	if(left >= right) return .5 * (left + go(v->left, max(alt, right+v->ow)) + v->ow);
	return .5 * (right + go(v->right, max(alt, left+v->ow)) + v->ow);
}

int main()
{
	node * root = new node(0);
	scanf("%d%d", &h, &Q);
	while(Q--)
	{
		scanf("%s", ex);
		if(ex[0] == 'a')
		{
			int v,e;
			scanf("%d%d", &v, &e);
			long long pw = 1;
			while(pw <= v) pw *= 2;
			pw /= 4;
			node *q = root;
			root -> val += e;
			while(pw > 0)
			{
				if(v&pw)
				{
					if(q->right == NULL)
						q->right = new node(e);
					else q->right->val += e;
					q = q->right;
				}
				else
				{
					if(q->left == NULL)
						q->left = new node(e);
					else q->left->val += e;
					q = q->left;
				}
				pw /= 2;
			}
			q->ow += e;
		}
		else
		{
			printf("%.7lf\n", go(root, 0));
		}
	}
}